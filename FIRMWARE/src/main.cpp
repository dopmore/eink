#include <Arduino.h>

#define ENABLE_GxEPD2_GFX

#include <Adafruit_TinyUSB.h>
#include <Adafruit_GFX.h>
#include <GxEPD2_BW.h>
#include <Fonts/FreeMonoBold9pt7b.h>
#include <Fonts/FreeMonoBold12pt7b.h>
#include <SPI.h>
#include <SdFat.h>

// Using SDIO
SdFat SD;

File32 file; // current Ebook file
File32 root; // root dir

// USB Mass Storage (MSC)
Adafruit_USBD_MSC usb_msc;

#define PIN_SD_DAT0 22 // DAT0-3: GPIO22 - GPIO25
#define PIN_SD_SCK 20
#define PIN_SD_CMD 21

#define SD_CONFIG SdioConfig(PIN_SD_SCK, PIN_SD_CMD, PIN_SD_DAT0)

#define EPD_BUSY 9
#define EPD_RST 10
#define EPD_DC 11
#define EPD_CS 12
#define EPD_CLK 18
#define EPD_MOSI 19

arduino::MbedSPI EPD_SPI(-1, EPD_MOSI, EPD_CLK);

GxEPD2_BW<GxEPD2_290_GDEY029T94, GxEPD2_290_GDEY029T94::HEIGHT> display(GxEPD2_290_GDEY029T94(EPD_CS, EPD_DC, EPD_RST, EPD_BUSY));

// Inputs
#define MDS_RIGHT 1
#define MDS_LEFT 2
#define MDS_CENTER 3
#define SELECT 5

int32_t msc_read_cb(uint32_t lba, void *buffer, uint32_t bufsize);
int32_t msc_write_cb(uint32_t lba, uint8_t *buffer, uint32_t bufsize);
void msc_flush_cb(void);

void print_rootdir(File32 *rdir);

bool is_mounted; // avoid unneccesary checks
bool msc_ready;

int start = 0;     // starting idx of the text
bool npage = true; // new page accessed
char textbuffer[100];
int textlen = 100;
int bookmark = 0;

void setup()
{
  Serial.begin(115200);
  delay(1000);

  display.epd2.selectSPI(EPD_SPI, SPISettings(4000000, MSBFIRST, SPI_MODE0));
  display.init(115200);

  // Inputs
  pinMode(MDS_RIGHT, INPUT_PULLUP);
  pinMode(MDS_LEFT, INPUT_PULLUP);
  pinMode(MDS_CENTER, INPUT_PULLUP);
  pinMode(SELECT, INPUT_PULLUP);

  // setting up SD card
  if (!SD.begin(SD_CONFIG))
  {
    SD.initErrorHalt(&Serial);
  }
  Serial.println("SDcard Initialized successfully!");
  // Seting up the SD card as a Mass Storage Device

  usb_msc.setID("Dopmore", "SD-Card", "1.00");
  usb_msc.setReadWriteCallback(msc_read_cb, msc_write_cb, msc_flush_cb);
  usb_msc.setUnitReady(false);
  usb_msc.begin();
  // re-enumeration
  if (TinyUSBDevice.mounted())
  {
    TinyUSBDevice.detach();
    delay(10);
    TinyUSBDevice.attach();
  }
  delay(100);
  // SD Card size

  uint32_t block_count = SD.card()->sectorCount();
  Serial.print("Volume size (MB):  ");
  Serial.println((block_count / 2) / 1024);

  usb_msc.setCapacity(block_count, 512);

  root = SD.open("/"); // list files
  print_rootdir(root);
}

void loop()
{
  is_mounted = TinyUSBDevice.mounted();
  if (is_mounted)
  {
    msc_ready = true;
    usb_msc.setUnitReady(true);
    Serial.println("MSC mode enabled");
  }
  else
  {
    if (msc_ready)
    { // skip if msc is already turned off
      msc_ready = false;
      usb_msc.setUnitReady(false);
      Serial.println("MSC mode disabled");
    }
    if (SD.exists("book.txt"))
    {
      file = SD.open("book.txt");
    }

    if (npage)
    { // only refresh if a new page has been accessed
      if (start > file.size())
      {
        start = 0;
      }
      else if (start < 0)
      {
        start = file.size() - textlen;
      }
      display.clearScreen();
      display.setCursor(0, 0);
      display.setTextColor(GxEPD_BLACK);

      // go to current Position and write the next [max chars] that fit on the screen
      file.seek(start);
      start = file.position() - textlen; // stay at current position
      file.fgets(textbuffer, textlen);
      display.print(textbuffer);
      display.display();
      npage = false;
    }

    if (!digitalRead(MDS_LEFT))
    { // next page
      npage = true;
      start = start + textlen;
    }
    if (!digitalRead(MDS_RIGHT))
    { // last page
      npage = true;
      npage = true;
      start = start - textlen;
    }
    if (!digitalRead(MDS_CENTER))
    { // make a bookmark
      bookmark = start;
    }
    if (!digitalRead(SELECT))
    { // access bookmark
      npage = true;
      start = bookmark;
    }
  }
}

void print_rootdir(File32 &rdir)
{
  File32 file;
  while (file.openNext(&rdir, O_RDONLY))
  { // read only
    display.println(file.name());

    if (file.isDir())
    {
      display.write("/");
    }
    else
    {
      display.write(file.size()); // show file size if it is a file
    }

    display.println();
    file.close();
  }
}

// READ/WRITE functions for the MSC mode

// Refer to: https://github.com/adafruit/Adafruit_TinyUSB_Arduino/blob/master/examples/MassStorage/msc_sdfat/msc_sdfat.ino

// Callback invoked when received READ10 command.
// Copy disk's data to buffer (up to bufsize) and
// return number of copied bytes (must be multiple of block size)
int32_t msc_read_cb(uint32_t lba, void *buffer, uint32_t bufsize)
{
  bool rc = SD.card()->readSectors(lba, (uint8_t *)buffer, bufsize / 512);
  return rc ? bufsize : -1;
}

// Callback invoked when received WRITE10 command.
// Process data in buffer to disk's storage and
// return number of written bytes (must be multiple of block size)

int32_t msc_write_cb(uint32_t lba, uint8_t *buffer, uint32_t bufsize)
{
#ifdef LED_BUILTIN
  digitalWrite(LED_BUILTIN, HIGH);
#endif
  bool rc = SD.card()->writeSectors(lba, buffer, bufsize / 512);
  return rc ? bufsize : -1;
}

// Callback invoked when WRITE10 command is completed (status received and accepted by host).
// used to flush any pending cache.
void msc_flush_cb(void)
{
  SD.card()->syncDevice();
  SD.cacheClear(); // clear file system's cache to force refresh
}