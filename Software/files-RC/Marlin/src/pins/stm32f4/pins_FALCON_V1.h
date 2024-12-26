/**
 * Marlin 3D Printer Firmware
 * Copyright (C) 2016 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (C) 2011 Camiel Gubbels / Erik van der Zalm
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

/* Pin Assignments:
 *
 * A0  TM2_CH1 PWM      | B0  NC               | C0  NC               | D0  CAN_RX           | E0  NC               |
 * A1  TM2_CH2 PWM      | B1  NC               | C1  NC               | D1  CAN_TX           | E1  NC               |
 * A2  TM2_CH3 PWM      | B2  BOOT 1           | C2  PT1000/2         | D2  NC               | E2  NC               |
 * A3  TM2_CH4 PWM      | B3  X_DIR            | C3  PT1000/1         | D3  X_STEP           | E3  NC               |
 * A4  NC               | B4  Y_DIR            | C4  TR/2             | D4  Y_STEP           | E4  NC               |
 * A5  NC               | B5  Z_DIR            | C5  TR/1             | D5  Z_STEP           | E5  TM9_CH1 PWM      |
 * A6  TM3_CH1 PWM      | B6  A_DIR            | C6  KILL             | D6  A_STEP           | E6  TM9_CH2 PWM      | 
 * A7  TM3_CH1 PWM      | B7  B_DIR            | C7  SD_DET           | D7  B_STEP           | E7  PS_ON            |
 * A8  NC               | B8  SCL              | C8  ENC              | D8  L-RX/TX          | E8  PROBE_IN         |
 * A9  NC               | B9  SDA              | C9  BEEP             | D9  L_RX/RX          | E9  PROBE_OUT        |
 * A10 NC               | B10 EN2              | C10 DRIVE_TX         | D10 L_D5             | E10 FILAMENT         |
 * A11 USB D-           | B11 EN1              | C11 DRIVE_RX         | D11 L_D4             | E11 B_MIN            |
 * A12 USB D+           | B12 SS               | C12 ENA_MOTOR        | D12 L_D7             | E12 A_MIN            |
 * A13 SWDIO            | B13 SCK              | C13 NC               | D13 L_D6             | E13 Z_MIN            |
 * A14 SWCLK            | B14 MISO             | C14 OSC2_IN          | D14 NC               | E14 Y_MIN            |
 * A15 NC               | B15 MOSI             | C15 OSC2_OUT         | D15 NC               | E15 X_MIN            |
 */
 
#if NOT_TARGET(STM32F4)
  #error "Oops! Select an STM32F4 board in 'Tools > Board.'"
#elif HOTENDS > 2 || E_STEPPERS > 2
  #error "Too many HOTENDs."
#endif

#define DEFAULT_MACHINE_NAME "FALCON"

//
// Limit Switches
//
   
#define X_STOP_PIN                     PE15
#define Y_STOP_PIN                     PE14
#define Z_STOP_PIN                     PE13
#define A_STOP_PIN                     PE12
#define B_STOP_PIN                     PE11   
                                     
//
// Steppers
//
// X,Y,Z,E0 enable are the same

#define X_STEP_PIN                     PD3
#define X_DIR_PIN                      PB3
#define X_ENABLE_PIN                   PC12
#define X_SERIAL_TX_PIN                PC10
#define X_SERIAL_RX_PIN                PC11

#define Y_STEP_PIN                     PD4
#define Y_DIR_PIN                      PB4
#define Y_ENABLE_PIN                   PC12
#define Y_SERIAL_TX_PIN                PC10
#define Y_SERIAL_RX_PIN                PC11

#define Z_STEP_PIN                     PD5
#define Z_DIR_PIN                      PB5
#define Z_ENABLE_PIN                   PC12
#define Z_SERIAL_TX_PIN                PC10
#define Z_SERIAL_RX_PIN                PC11

#define A_STEP_PIN                     PD6
#define A_DIR_PIN                      PB6
#define A_ENABLE_PIN                   PC12
#define A_SERIAL_TX_PIN                PC10
#define A_SERIAL_RX_PIN                PC11

#define B_STEP_PIN                     PD7
#define B_DIR_PIN                      PB7
#define B_ENABLE_PIN                   PC12
#define B_SERIAL_TX_PIN                PC10
#define B_SERIAL_RX_PIN                PC11

#define E0_STEP_PIN                    A_STEP_PIN
#define E0_DIR_PIN                     A_DIR_PIN
#define E0_ENABLE_PIN                  A_ENABLE_PIN  
#define E0_SERIAL_TX_PIN               A_SERIAL_TX_PIN
#define E0_SERIAL_RX_PIN               A_SERIAL_RX_PIN

#define E1_STEP_PIN                    B_STEP_PIN
#define E1_DIR_PIN                     B_DIR_PIN
#define E1_ENABLE_PIN                  B_ENABLE_PIN  
#define E1_SERIAL_TX_PIN               B_SERIAL_TX_PIN
#define E1_SERIAL_RX_PIN               B_SERIAL_RX_PIN

#define TMC_BAUD_RATE 19200

//
// Temperature Sensors
//

#define TEMP_0_PIN                     PC3
#define TEMP_1_PIN                     PC2
#define TEMP_BED_PIN                   PC5
#define TEMP_CHAMBER_PIN               PC4

//
// Heaters / Fans
//

#define HEATER_0_PIN                   PE5
#define HEATER_1_PIN                   PE6
#define HEATER_2_PIN                   PA0
#define HEATER_3_PIN                   PA1

#define HEATER_TTL0_PIN                PA7
#define HEATER_TTL1_PIN                PA6

#define HEATER_BED_PIN                 HEATER_TTL0_PIN
#define HEATER_CHAMBER_PIN             HEATER_TTL1_PIN 

#define FAN0_PIN                       PA3
#define FAN1_PIN                       PA2

#ifdef E0_AUTO_FAN_PIN
  #undef E0_AUTO_FAN_PIN
  #define E0_AUTO_FAN_PIN  FAN1_PIN
#endif

//
// EEPROM settings
// EEPROM Emulation
//

#define I2C_EEPROM 
#define MARLIN_EEPROM_SIZE             0x1000                        // 4K
#define I2C_SCL_PIN                    PB8
#define I2C_SDA_PIN                    PB9

//
// BL-TOUCH
//

#define SERVO0_PIN                     PE8
#define Z_MIN_PROBE_PIN                PE9

//
// Various
//

#define FIL_RUNOUT1_PIN                PE10
#define FIL_MOTION1_PIN                PE10
#define PS_ON_PIN                      PE7

/*
 *                 _________                                            _________                            
 *            5V   |  1  2 | GND                          (KILL)  PC6   |  1  2 | GND                        
 *  (LCD_D7)  PD12 |  3  4 | PD13  (LCD_D6)                       RESET |  3  4 | PC7  (SD_DET)                        
 *  (LCD_D5)  PD10 |  5  6 | PD11  (LCD_D4)               (MOSI)  PB15  |  5  6 | PB10 (BTN_EN2)             
 *  (LCD_RS)  PD8  |  7  8 | PD9   (LCD_EN)               (SD_SS) PB12  |  7  8 | PB11 (BTN_EN1)             
 *  (BTN_ENC) PC8  |  9  10| PC9   (BEEP)                 (SCK)   PB13  |  9  10| PB14 (MISO)                
 *                 ¯¯¯¯¯¯¯¯¯                                            ¯¯¯¯¯¯¯¯¯                            
 *                   EXP1                                                  EXP2                              
 */

#define EXP_1_01_PIN                   -1
#define EXP_1_02_PIN                   -1
#define EXP_1_03_PIN                   PD12
#define EXP_1_04_PIN                   PD13
#define EXP_1_05_PIN                   PD10
#define EXP_1_06_PIN                   PD11
#define EXP_1_07_PIN                   PD8
#define EXP_1_08_PIN                   PD9
#define EXP_1_09_PIN                   PC8
#define EXP_1_10_PIN                   PC9

#define EXP_2_01_PIN                   PC6
#define EXP_2_02_PIN                   -1
#define EXP_2_03_PIN                   -1
#define EXP_2_04_PIN                   PC7
#define EXP_2_05_PIN                   PB15
#define EXP_2_06_PIN                   PB10
#define EXP_2_07_PIN                   PB12
#define EXP_2_08_PIN                   PB11
#define EXP_2_09_PIN                   PB13
#define EXP_2_10_PIN                   PB14

// HAL SPI2 pins

/* Работает только со вставленной SD картой */

#define ENABLE_SPI2                                        // HAL SPI2 pins

#ifdef PIN_SPI_SCK
  #undef PIN_SPI_SCK
#endif

#ifdef PIN_SPI_SS
  #undef PIN_SPI_SS
#endif

#ifdef PIN_SPI_MISO
  #undef PIN_SPI_MISO
#endif

#ifdef PIN_SPI_MOSI
  #undef PIN_SPI_MOSI
#endif


#define PIN_SPI_SCK                    EXP_2_09_PIN                  // SPI2 SCLK
#define PIN_SPI_SS                     EXP_2_07_PIN                  // SPI2 SSEL
#define PIN_SPI_MISO                   EXP_2_10_PIN                  // SPI2 MISO
#define PIN_SPI_MOSI                   EXP_2_05_PIN                  // SPI2 MOSI

/*
#ifndef SDCARD_CONNECTION
  #define SDCARD_CONNECTION                LCD
#endif
*/

// SDCard
#ifdef SDSUPPORT
  #define SDSS                       EXP_2_07_PIN
  #define SD_DETECT_PIN              EXP_2_04_PIN
  #define KILL_PIN                   EXP_2_01_PIN
#endif

//
// LCD / Controller
//
#if HAS_WIRED_LCD
  #define BEEPER_PIN                 EXP_1_10_PIN
  #define BTN_ENC                    EXP_1_09_PIN

 #if ENABLED(CR10_STOCKDISPLAY)

   #define LCD_PINS_RS               EXP_1_07_PIN
  
   #define BTN_EN1                   EXP_1_03_PIN
   #define BTN_EN2                   EXP_1_05_PIN
  
   #define LCD_PINS_EN               EXP_1_08_PIN
   #define LCD_PINS_D4               EXP_1_06_PIN

#elif IS_TFTGLCD_PANEL

    #undef BEEPER_PIN
    #undef BTN_ENC

    #if ENABLED(TFTGLCD_PANEL_SPI)
      #define TFTGLCD_CS             EXP_2_08_PIN
    #endif

    #define SD_DETECT_PIN            EXP_2_04_PIN

#else

    #define LCD_PINS_RS              EXP_1_07_PIN

    #define BTN_EN1                  EXP_2_08_PIN
    #define BTN_EN2                  EXP_2_06_PIN

    #define LCD_PINS_EN              EXP_1_08_PIN

    #if ENABLED(FYSETC_MINI_12864)

      #define DOGLCD_CS              EXP_1_08_PIN
      #define DOGLCD_A0              EXP_1_07_PIN
      #define LCD_BACKLIGHT_PIN      -1
      #define LCD_RESET_PIN          EXP_1_06_PIN                              // Must be high or open for LCD to operate normally.

      #define LCD_CONTRAST_INIT      240
      #define LCD_CONTRAST_MIN       200
      #define LCD_CONTRAST_MAX       255
      
      #if EITHER(FYSETC_MINI_12864_1_2, FYSETC_MINI_12864_2_0)
        #ifndef RGB_LED_R_PIN
          #define RGB_LED_R_PIN      EXP_1_05_PIN
        #endif
        #ifndef RGB_LED_G_PIN
          #define RGB_LED_G_PIN      EXP_1_04_PIN
        #endif
        #ifndef RGB_LED_B_PIN
          #define RGB_LED_B_PIN      EXP_1_03_PIN
        #endif
      #elif ENABLED(FYSETC_MINI_12864_2_1)
        #define NEOPIXEL_PIN         EXP_1_05_PIN
      #endif

    #else                                                                      // !FYSETC_MINI_12864

      #define LCD_PINS_D4            EXP_1_06_PIN

      #if IS_ULTIPANEL
        #define LCD_PINS_D5          EXP_1_05_PIN
        #define LCD_PINS_D6          EXP_1_04_PIN
        #define LCD_PINS_D7          EXP_1_03_PIN

        #if ENABLED(REPRAP_DISCOUNT_FULL_GRAPHIC_SMART_CONTROLLER)
          #define BTN_ENC_EN         LCD_PINS_D7                               // Detect the presence of the encoder
        #endif
      #endif

    #endif                                                                     // !FYSETC_MINI_12864

#if IS_U8GLIB_ST7920
  #define BOARD_ST7920_DELAY_1                96
  #define BOARD_ST7920_DELAY_2                48
  #define BOARD_ST7920_DELAY_3               640
#endif

  #endif

#endif                                                                         // HAS_WIRED_LCD