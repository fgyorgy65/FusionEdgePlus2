/* https://github.com/SimZs/FusionEdge */
/* esp32-S3-devkit-C1 44 pins https://randomnerdtutorials.com/esp32-s3-devkitc-pinout-guide */

#pragma once
#include "myoptions.local.h"
#ifndef ARDUINO_ESP32S3_DEV
    #define ARDUINO_ESP32S3_DEV
#endif

#define LANGUAGE HU // HU NL PL RU EN EL Enter your own language here!!
#define NAMEDAYS_FILE HU // HU, PL, NL
#define CLOCK_TTS_LANGUAGE "hu" //Default language TTS e.g. pl,en,de,ru,fr,hu
// #define IMPERIALUNIT // English weather: Fahrenheit, inHg and mph (requires LANGUAGE EN)

// Optional current-track album art from Last.fm (WEB, SD, DLNA and Bluetooth metadata).
#define USE_LASTFM_COVER
#define LASTFM_API_KEY "YOUR_API_KEY"

// Animated cassette replaces the clock during the non-blank "While playing" screensaver.
#define USE_CASSETTE_SCREENSAVER
// #define CASSETTE_FRAME_MS 100UL // Reel animation interval; lower values increase display load.
// #define CASSETTE_PNG_PATH "/images/screensaver/retro_audio_cassette.png"      // Silver/green cassette.
// #define CASSETTE_PNG_PATH "/images/screensaver/retro_audio_cassette_blue.png" // Blue/pink cassette.
// #define CASSETTE_PNG_PATH "/images/screensaver/retro_audio_cassette_red.png"  // Red/cream cassette.

// --- DLNA / Synology ---
//#define USE_DLNA
//#define dlnaHost "192.168.180.122"
//#define dlnaIDX  21

#define LEDSTRIP_PIN        48

#define RSSI_DIGIT       true

/******************************************/
#define LED_BUILTIN_S3  9 //  48     /* S3-onboard RGB led pin */
#define USE_BUILTIN_LED false /* The RGB LED does not turn on.. */
/*****************************************/
#define LGFX_LCD_SPI_HOST     2

//#define DSP_MODEL DSP_ILI9486
//#define DSP_MODEL DSP_ILI9488
#define DSP_MODEL DSP_ILI9341
//#define DSP_MODEL DSP_ST7735
//#define DSP_MODEL DSP_ST7789_76
//#define DSP_MODEL DSP_1602I2C    //2x16 
//#define DSP_MODEL DSP_2004I2C   //4x20
//#define DSP_MODEL DSP_ST7796
//#define DSP_MODEL DSP_SH1106
//#define SH1106_GRAYSCALE  true
//#define DSP_MODEL DSP_SSD1306
//#define DSP_MODEL DSP_GC9A01A
//#define HUN_LCD
/*****************************************/

#define TFT_DC 47 //9
#define TFT_CS 14 //14
#define TFT_RST 21 // -1
#define TFT_SCK   3 //1
#define TFT_MOSI  45 //3
#define TFT_MISO  46 //2
#define BRIGHTNESS_PIN -1 //14
/*****************************************/
// #define NEXTION_RX      15
// #define NEXTION_TX     16
/*****************************************/
/* Touch panel
 Resistive */
#define TS_MODEL TS_MODEL_XPT2046
#define SPIA_SCK	42 //1
#define SPIA_MISO	41 //2
#define SPIA_MOSI	2  //3
#define TS_SCK	42
#define TS_MISO	41
#define TS_MOSI	2
#define TS_CS	1
#define TS_SPI	'A'
//#define TS_IRQ	3

/* Capacitive*/
//#define TS_MODEL TS_MODEL_FT6X36
//#define TS_MODEL TS_MODEL_GT911
//#define TS_SDA 8
//#define TS_SCL 9
//#define TS_RST 42
//#define TS_INT 41
/*****************************************/
/* SD CARD */
//#define SD_SPI_HOST FSPI        // Переключаем хост SD-карты на FSPI (он же SPI2)
#define SDC_CS    7
#define SD_SPIPINS SPIA_SCK, SPIA_MISO, SPIA_MOSI, SDC_CS  // SCK, MISO, MOSI, CS
#define SD_SPI_HOST FSPI        // ESP32-S3: SD on SPI2, display/touch on SPI3
#define SDSPISPEED     16000000 
/****************************************/
/*  I2S DAC  */

/* PCM5102A  DAC */
#define I2S_LRC             38   //S1 38  WS = LRC = LCK narancs
#define I2S_DOUT            39   //S2 39  DIN            sárga  
#define I2S_BCLK            40   //S3 40  BCK  zöld
   

/* ENCODER 1 */
#define ENC_BTNR 6  // zöld       15 // S2
#define ENC_BTNL 5  // sárga      16 // S1
#define ENC_BTNB 4  // narancs    17 // KEY
#define ENC_INTERNALPULLUP		true
//#define ENC_HALFQUARD true  // true = 2 steps per click, false = 4 steps per click   , az otions.h-ban van a beállítás, itt csak a komment
#define BTN_CLICK_TICKS 300

/* ENCODER 2 */
/*#define ENC2_BTNR 7 // S2
#define ENC2_BTNL 16 // S1
#define ENC2_BTNB 15 // KEY
#define ENC2_INTERNALPULLUP		true*/

/* BLUETOOTH MODUL (QCC5124EL, AT parancskészlet) */
// Comment out to build FusionEdge without the QCC Bluetooth module.
//#define USE_BLUETOOTH

//#define BT_UART_TX   45   // ESP32 TX -> modul RX
//#define BT_UART_RX   46   // ESP32 RX <- modul TX
//#define BT_UART_BAUD 115200

//#define BT_I2S_BCK   7    // modul I2S BCK  (volt ENC2_BTNR)
//#define BT_I2S_LRCK  15   // modul I2S LRCK (volt ENC2_BTNB)
//#define BT_I2S_DATA  16   // modul I2S DATA (volt ENC2_BTNL)
/********************************************/

/* ÓRA MODUL RTC DS3132 */
// #define RTC_SCL     9
// #define RTC_SDA     8
// #define RTC_MODULE DS3231
/********************************************/

/* REMOTE CONTROL INFRARED RECEIVER */
#define IR_PIN 17
#define WAKE_PIN1      17
#define WAKE_PIN2      4  // 17

/********************************************/

/********************************************/
/*  Egyéb beállítások.  */
//#define HAS_PLAYMODE_STATION_WIDGET
#define EXT_WEATHER  true
//#define MUTE_PIN     2            /*  MUTE Pin */
//#define MUTE_VAL    LOW          /*  Write this to MUTE_PIN when player is stop */
//#define PLAYER_FORCE_MONO false  /*  mono option on boot - false stereo, true mono. "false" */
#define I2S_INTERNAL    false    /*  If true - use esp32 internal DAC. "false" */
//#define ROTATE_90   false        /*  Optional 90 degree rotation for square displays."false"*/
//#define TFT_ROTATE      0        /*  Display rotation. 0 - 0, 1 - 90, 2 - 180, 3 - 270 degrees */
//#define HIDE_VOLPAGE             /* Hangerő elrejtés, navigálj a hangerő folyamatjelző sávjával.*/
//#define LIGHT_SENSOR      40               /*  Light sensor  */
//#define AUTOBACKLIGHT(x)  *function*        /*  Autobacklight function. See options.h for example  */
//#define NAME_STRIM              /* Az állomás nevének megjelenítése a streamből. (MOD Maleksm)*/

//#define DOWN_LEVEL           2      /* lowest level brightness (from 0 to 255) */
//#define DOWN_INTERVAL        60     /* interval for BacklightDown in sec (60 sec = 1 min) */
/* ***************************************** */

#define ENC_HALFQUARD       255