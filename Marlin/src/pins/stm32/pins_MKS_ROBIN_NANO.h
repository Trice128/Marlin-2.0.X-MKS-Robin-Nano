/**
 * Marlin 3D Printer Firmware
 * Copyright (c) 2020 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */
#pragma once

/**
 * MKS Robin nano (STM32F130VET6) board pin assignments
 */

#ifndef __STM32F1__
  #error "Oops! Select an STM32F1 board in 'Tools > Board.'"
#elif HOTENDS > 2 || E_STEPPERS > 2
  #error "MKS Robin nano supports up to 2 hotends / E-steppers. Comment out this line to continue."
#endif

#define BOARD_INFO_NAME "MKS Robin nano"

//
// Release PB4 (Y_ENABLE_PIN) from JTAG NRST role
//
#define DISABLE_DEBUG

//
// EEPROM
//
//#define SDCARD_EEPROM_EMULATION        // Activate if EEPROM is to be saved on the SD card...
#define SPI_FLASH_EEPROM_EMULATION       // Deactivate if EEPROM is to be saved on the SD card, SPI_FLASH_EEPROM_EMULATION must then be //...
#define SPI_FLASH_EEPROM_OFFSET 0x700000
#define SPI_FLASH_DEVICE 2
#define SPI_FLASH_CS_PIN PB12

//
// Limit Switches
//
#define X_STOP_PIN        PA15
#define Y_STOP_PIN        PA12
#define Z_MIN_PIN         PA11
#define Z_MAX_PIN         PC4

#ifndef FIL_RUNOUT_PIN
  #define FIL_RUNOUT_PIN   PA4   // MT_DET
#endif

//
// Steppers
//
#define X_ENABLE_PIN       PE4
#define X_STEP_PIN         PE3
#define X_DIR_PIN          PE2

#define Y_ENABLE_PIN       PE1
#define Y_STEP_PIN         PE0
#define Y_DIR_PIN          PB9

#define Z_ENABLE_PIN       PB8
#define Z_STEP_PIN         PB5
#define Z_DIR_PIN          PB4

#define E0_ENABLE_PIN      PB3
#define E0_STEP_PIN        PD6
#define E0_DIR_PIN         PD3

//#define E1_ENABLE_PIN                     PA3  // USED BY UART X
//#define E1_STEP_PIN                       PA6  // USED BY UART Y
//#define E1_DIR_PIN                        PA1  // USED BY UART Z

//
//TMC UART RX / TX Pins
//
#if HAS_TMC220x
  /**
   * TMC2208/TMC2209 stepper drivers
   *
   * Hardware serial communication ports.
   * If undefined software serial is used according to the pins below
   */
  //#define X_HARDWARE_SERIAL  Serial1
  //#define Y_HARDWARE_SERIAL  Serial1
  //#define Z_HARDWARE_SERIAL  Serial1
  //#define E0_HARDWARE_SERIAL Serial1

  //
  // Software serial
  //
  #define X_SERIAL_TX_PIN                   PA3
  #define X_SERIAL_RX_PIN                   PA3

  #define Y_SERIAL_TX_PIN                   PA6
  #define Y_SERIAL_RX_PIN                   PA6

  #define Z_SERIAL_TX_PIN                   PA1
  #define Z_SERIAL_RX_PIN                   PA1

  #define E0_SERIAL_TX_PIN                  PE5
  #define E0_SERIAL_RX_PIN                  PE5

  // Reduce baud rate to improve software serial reliability
  #define TMC_BAUD_RATE 19200
#endif

//
// Servos
//
#define SERVO0_PIN                          PA8   // Enable BLTOUCH support ROBIN NANO v1.2 ONLY

//
// Temperature Sensors
//
#define TEMP_0_PIN         PC1   // TH1
#define TEMP_1_PIN         PC2   // TH2
#define TEMP_BED_PIN       PC0   // TB1

//
// Heaters / Fans
//
#define HEATER_0_PIN       PC3   // HEATER1
#define HEATER_1_PIN       PB0   // HEATER2
#define HEATER_BED_PIN     PA0   // HOT BED

#define FAN_PIN            PB1   // FAN
#define E0_AUTO_FAN    PB0

//
// Thermocouples
//
//#define MAX6675_SS_PIN     PE5  // TC1 - CS1  //USED BY UART Z
//#define MAX6675_SS_PIN     PE6  // TC2 - CS2

//
// Misc. Functions
//
//#define POWER_LOSS_PIN     PA2   // PW_DET
//#define PS_ON_PIN          PA3   // PW_OFF

//
// LED / NEOPixel
//

//#define LED_PIN            PB2
#define NEO_PIXEL_1        PA10  // USED WIFI RX PIN
#define NEO_PIXEL_2        PA9   // USED WIFI TX PIN

//
// WIFI ESP8266 
//
//#define WIFI_TX_PIN    PA10
//#define WIFI_RX_PIN    PA9
//#define WIFI_IO0_PIN   PC13
//#define WIFI_IO1_PIN   PC7

//
// SD Card
//
#ifndef SDCARD_CONNECTION
  #define SDCARD_CONNECTION              ONBOARD
#endif

#define SDIO_SUPPORT
#define SD_DETECT_PIN                       PD12
#define ONBOARD_SD_CS_PIN                   PC11

//
// LCD / Controller
//
#define BEEPER_PIN                          PC5

//
// LCD / Controller
//
#define BEEPER_PIN         PC5

/**
 * Note: MKS Robin TFT screens use various TFT controllers.
 * If the screen stays white, disable 'LCD_RESET_PIN'
 * to let the bootloader init the screen.
 */
#if ENABLED(FSMC_GRAPHICAL_TFT)
  //@
  #define DOGLCD_MOSI -1 // prevent redefine Conditionals_post.h
  #define DOGLCD_SCK -1

  #define FSMC_CS_PIN        PD7    // NE4
  #define FSMC_RS_PIN        PD11   // A0

  #define LCD_USE_DMA_FSMC // DMA transfer to TFT?
  #define FSMC_DMA_DEV DMA2
  #define FSMC_DMA_CHANNEL DMA_CH5

  //#define LCD_RESET_PIN      PC6    // FSMC_RST
  //#define NO_LCD_REINIT             // Suppress LCD re-initialization

  #define LCD_BACKLIGHT_PIN  PD13

  #if ENABLED(TOUCH_BUTTONS)
    #define TOUCH_CS_PIN     PA7  // SPI2_NSS
    #define TOUCH_SCK_PIN    PB13 // SPI2_SCK
    #define TOUCH_MISO_PIN   PB14 // SPI2_MISO
    #define TOUCH_MOSI_PIN   PB15 // SPI2_MOSI
  #endif
#endif
