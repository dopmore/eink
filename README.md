<img width="1752" height="2480" alt="Tiny  e-reader" src="https://github.com/user-attachments/assets/22f554e1-e2b3-4a42-beb2-54f6d1262126" />

# Tiny-e-ink-Ebook-reader
This project aims to create a small portable e-reader, using an E-ink Display and a SD-card for storage.
It includes a Multi Directional Switch and a Select Button for inputs. While the MDS is for navigation (Next Page / Last Page), the select button is used to make a book mark and the middle button of the MDS then can be used to go back to the saved bookmark. 

I wanted to make this to be able to read books anywhere at any time without needing to carry around a big e-reader or get distracted by my phone :)!

## CAD / Assembly
<img width="1059" height="644" alt="image" src="https://github.com/user-attachments/assets/9afac81e-27f0-4661-9cc3-7a1dce958651" />
<img width="917" height="402" alt="image" src="https://github.com/user-attachments/assets/aa2cfd22-4899-4e7b-966f-87c9054c4b6e" />

The Assembly is easy as the case consists of only two parts that slide into each other and trap the PCB + Battery in between.

## PCB
<img width="1102" height="710" alt="eink2" src="https://github.com/user-attachments/assets/b1bf493b-dc03-4811-8bdd-73be98d7200b" />

<img width="430" height="656" alt="image" src="https://github.com/user-attachments/assets/510796b6-1f57-4809-bf77-45e71ed86e5d" />

The PCB will be soldered using a hotplate.

## Schematics
<img width="4960" height="3507" alt="image" src="https://github.com/user-attachments/assets/7ca8a65a-fe31-4dc1-880f-cc72cb0f937a" />

## PCB-order:
<img width="410" height="501" alt="image" src="https://github.com/user-attachments/assets/cd461f04-6f38-4001-a829-165cbbb267f9" />

## Parts (LCSC):
<img width="394" height="481" alt="image" src="https://github.com/user-attachments/assets/32092646-83ca-469a-b6b1-09ba60e69f98" />


## BOM
| Component                                | Link    / Company                                              | Price            | Shipping | 
| ---- | ---- | ---- | ---- |
| PCB + Stencil                            | jlcpcb.com | $12.44         | free (coupon) |
| PCB-Parts  | lcsc.com | $15.42 | $8.95 |
| 103450 3,7 V 1500 mAh Polymer-Lithium-Akku jst PH 2,0 mm                        | https://www.aliexpress.com/item/1005009590723370.html | $7.60 | free |
| E-paper Screen 296x128 (GDEY029T94)                | https://buy-lcd.com/products/29-inch-e-paper-screen-296x128-raspberry-pi-spi-display-gdey029t94?VariantsId=10173 | $7.91         | $10 |

Total: 62.32 (Incl. Shipping)

## Parts-Bom

| Index | LCSC#     | MPN                      | Manufacturer                 | Package                             | Customer # | Description                                                                                 | RoHS | Quantity | MOQ | Multiple | Unit Price ($) | Extended Price ($) | Product Link                                                                                             |
| ----- | --------- | ------------------------ | ---------------------------- | ----------------------------------- | ---------- | ------------------------------------------------------------------------------------------- | ---- | -------- | --- | -------- | -------------- | ------------------ | -------------------------------------------------------------------------------------------------------- |
| 1     | C325532   | RMC04022.21%N            | TyoHM                        | 0402                                |            | 2.2Ω ±1% 62.5mW 0402 Thick Film Resistor                                                    | yes  | 100      | 100 | 100      | 0.0034         | 0.34               | [https://www.lcsc.com/product-detail/C325532.html](https://www.lcsc.com/product-detail/C325532.html)     |
| 2     | C71911    | 16-213SDRC/S530-A3/TR8   | EVERLIGHT                    | 0402                                |            | Red 650nm LED Indication - Discrete 2V 0402                                                 | yes  | 20       | 20  | 20       | 0.0330         | 0.66               | [https://www.lcsc.com/product-detail/C71911.html](https://www.lcsc.com/product-detail/C71911.html)       |
| 3     | C77336    | MBR0530                  | JSCJ                         | SOD-123                             |            | Diode 30V 500mA Surface Mount SOD-123                                                       | yes  | 20       | 20  | 20       | 0.0332         | 0.66               | [https://www.lcsc.com/product-detail/C77336.html](https://www.lcsc.com/product-detail/C77336.html)       |
| 4     | C7603347  | SI1308EDL                | TECH PUBLIC                  | SOT-323                             |            | 30V 1.4A 360mW Surface Mount SOT-323                                                        | yes  | 5        | 5   | 5        | 0.0840         | 0.42               | [https://www.lcsc.com/product-detail/C7603347.html](https://www.lcsc.com/product-detail/C7603347.html)   |
| 5     | C52923    | CL05A105KA5NQNC          | Samsung Electro-Mechanics    | 0402                                |            | 1uF ±10% 25V Ceramic Capacitor X5R 0402                                                     | yes  | 100      | 100 | 100      | 0.0040         | 0.40               | [https://www.lcsc.com/product-detail/C52923.html](https://www.lcsc.com/product-detail/C52923.html)       |
| 6     | C511277   | MCP1700-3302E/TO         | MICROCHIP                    | TO-92-3                             |            | 3.3V Positive Fixed TO-92-3 Voltage Regulators - Linear, Low Drop Out (LDO) Regulators RoHS | yes  | 1        | 1   | 1        | 0.8030         | 0.80               | [https://www.lcsc.com/product-detail/C511277.html](https://www.lcsc.com/product-detail/C511277.html)     |
| 7     | C481407   | NX3225GA-12MHZ-STD-CRG-2 | NDK                          | SMD3225-4P                          |            | Crystal 12MHz ±20ppm 8pF 100Ω SMD3225-4P                                                    | yes  | 5        | 5   | 5        | 0.2377         | 1.19               | [https://www.lcsc.com/product-detail/C481407.html](https://www.lcsc.com/product-detail/C481407.html)     |
| 8     | C47647    | PH-2P                    | BOOMELE(Boom Precision Elec) | SMD,P=2mm,Surface Mount,Right Angle |            | Connector Header 2 position 2mm Pitch Surface Mount, Right Angle                            | yes  | 12       | 12  | 12       | 0.0614         | 0.74               | [https://www.lcsc.com/product-detail/C47647.html](https://www.lcsc.com/product-detail/C47647.html)       |
| 9     | C424093   | MCP73831T-2ACI/OT        | MICROCHIP                    | SOT-23-5                            |            | 3.75V~6V Lithium Battery 1 550mA SOT-23-5 Battery Chargers ICs RoHS                         | yes  | 1        | 1   | 1        | 0.7611         | 0.76               | [https://www.lcsc.com/product-detail/C424093.html](https://www.lcsc.com/product-detail/C424093.html)     |
| 10    | C4109     | 0402WGF2001TCE           | UNI-ROYAL                    | 0402                                |            | 2kΩ ±1% 62.5mW 0402 Thick Film Resistor                                                     | yes  | 100      | 100 | 100      | 0.0008         | 0.08               | [https://www.lcsc.com/product-detail/C4109.html](https://www.lcsc.com/product-detail/C4109.html)         |
| 11    | C410351   | TF-015                   | Hanbo Electronic             | SMD                                 |            | Micro SD card (TF card) Connector and Ejector Push-Push Surface Mount                       | yes  | 5        | 5   | 5        | 0.1383         | 0.69               | [https://www.lcsc.com/product-detail/C410351.html](https://www.lcsc.com/product-detail/C410351.html)     |
| 12    | C388885   | EVQPUD02K                | PANASONIC                    | SMD,4.7x4.5mm                       |            | Tactile Switch SPST 2.2N 1.65mm J-Lead 4.7mm x 4.5mm Surface Mount, Right Angle             | yes  | 5        | 5   | 5        | 0.2299         | 1.15               | [https://www.lcsc.com/product-detail/C388885.html](https://www.lcsc.com/product-detail/C388885.html)     |
| 13    | C354600   | CKCS5020-47uH/M          | CENKER                       | SMD,5x5mm                           |            | 750mA 47uH ±20% 770mA 580mΩ Magnetic Shielded Inductor SMD,5x5mm Fixed Inductors RoHS       | yes  | 10       | 10  | 10       | 0.0504         | 0.50               | [https://www.lcsc.com/product-detail/C354600.html](https://www.lcsc.com/product-detail/C354600.html)     |
| 14    | C347476   | AO3401A                  | UMW                          | SOT-23                              |            | P-Channel 30V 4.2A 1.4W Surface Mount SOT-23                                                | yes  | 20       | 20  | 20       | 0.0321         | 0.64               | [https://www.lcsc.com/product-detail/C347476.html](https://www.lcsc.com/product-detail/C347476.html)     |
| 15    | C11702    | 0402WGF1001TCE           | UNI-ROYAL                    | 0402                                |            | 1kΩ ±1% 62.5mW 0402 Thick Film Resistor                                                     | yes  | 100      | 100 | 100      | 0.0011         | 0.11               | [https://www.lcsc.com/product-detail/C11702.html](https://www.lcsc.com/product-detail/C11702.html)       |
| 16    | C318954   | TM-2011                  | XKB Connection               | SMD-5P,19.7x14.8mm                  |            | SMD-5P,19.7x14.8mm Navigation Switches, Joystick RoHS                                       | yes  | 5        | 5   | 5        | 0.2672         | 1.34               | [https://www.lcsc.com/product-detail/C318954.html](https://www.lcsc.com/product-detail/C318954.html)     |
| 17    | C25905    | 0402WGF5101TCE           | UNI-ROYAL                    | 0402                                |            | 5.1kΩ ±1% 62.5mW 0402 Thick Film Resistor                                                   | yes  | 100      | 100 | 100      | 0.0009         | 0.09               | [https://www.lcsc.com/product-detail/C25905.html](https://www.lcsc.com/product-detail/C25905.html)       |
| 18    | C25744    | 0402WGF1002TCE           | UNI-ROYAL                    | 0402                                |            | 10kΩ ±1% 62.5mW 0402 Thick Film Resistor                                                    | yes  | 100      | 100 | 100      | 0.0013         | 0.13               | [https://www.lcsc.com/product-detail/C25744.html](https://www.lcsc.com/product-detail/C25744.html)       |
| 19    | C25100    | 0402WGF270JTCE           | UNI-ROYAL                    | 0402                                |            | 27Ω ±1% 62.5mW 0402 Thick Film Resistor                                                     | yes  | 100      | 100 | 100      | 0.0008         | 0.08               | [https://www.lcsc.com/product-detail/C25100.html](https://www.lcsc.com/product-detail/C25100.html)       |
| 20    | C2456208  | W25Q16JVZPIQ TR          | Winbond                      | WSON-8-EP(5x6)                      |            | 2.7V~3.6V 16Mbit 133MHz SPI WSON-8-EP(5x6) Memory (ICs) RoHS                                | yes  | 1        | 1   | 1        | 1.2904         | 1.29               | [https://www.lcsc.com/product-detail/C2456208.html](https://www.lcsc.com/product-detail/C2456208.html)   |
| 21    | C23733    | CL05A475MP5NRNC          | Samsung Electro-Mechanics    | 0402                                |            | 4.7uF ±20% 10V Ceramic Capacitor X5R 0402                                                   | yes  | 50       | 50  | 50       | 0.0059         | 0.30               | [https://www.lcsc.com/product-detail/C23733.html](https://www.lcsc.com/product-detail/C23733.html)       |
| 22    | C2040     | RP2040                   | Raspberry Pi                 | LQFN-56(7x7)                        |            | 133MHz 30 LQFN-56(7x7) Microcontrollers RoHS                                                | yes  | 1        | 1   | 1        | 0.9482         | 0.95               | [https://www.lcsc.com/product-detail/C2040.html](https://www.lcsc.com/product-detail/C2040.html)         |
| 23    | C19702    | CL10A106KP8NNNC          | Samsung Electro-Mechanics    | 0603                                |            | 10uF ±10% 10V Ceramic Capacitor X5R 0603                                                    | yes  | 50       | 50  | 50       | 0.0080         | 0.40               | [https://www.lcsc.com/product-detail/C19702.html](https://www.lcsc.com/product-detail/C19702.html)       |
| 24    | C19077718 | FPC-0.5FX-24PH20         | Yuandi                       | SMD,P=0.5mm                         |            | FFC/FPC Connector 24 Position 0.5mm Pitch Bottom Contact                                    | yes  | 5        | 5   | 5        | 0.0927         | 0.46               | [https://www.lcsc.com/product-detail/C19077718.html](https://www.lcsc.com/product-detail/C19077718.html) |
| 25    | C165948   | TYPE-C-31-M-12           | Korean Hroparts Elec         | SMD                                 |            | USB-C (USB TYPE-C) Receptacle Connector 16 Position Surface Mount                           | yes  | 5        | 5   | 5        | 0.1701         | 0.85               | [https://www.lcsc.com/product-detail/C165948.html](https://www.lcsc.com/product-detail/C165948.html)     |
| 26    | C1562     | 0402CG330J500NT          | FH                           | 0402                                |            | 33pF ±5% 50V Ceramic Capacitor C0G 0402                                                     | yes  | 100      | 100 | 100      | 0.0013         | 0.13               | [https://www.lcsc.com/product-detail/C1562.html](https://www.lcsc.com/product-detail/C1562.html)         |
| 27    | C1525     | CL05B104KO5NNNC          | Samsung Electro-Mechanics    | 0402                                |            | 100nF ±10% 16V Ceramic Capacitor X7R 0402                                                   | yes  | 100      | 100 | 100      | 0.0013         | 0.13               | [https://www.lcsc.com/product-detail/C1525.html](https://www.lcsc.com/product-detail/C1525.html)         |
