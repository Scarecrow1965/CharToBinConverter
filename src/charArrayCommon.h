// +-------------------------------------------------------------
//
// Equipment:
// ESP32, OLED SSD1306
//
// File: main.cpp
//
// Description:
//
// file to convert char array graphics and animations into binary file
// with the help of GitHub Copilot
//
// History:     22-Dec-2023     Scarecrow1965   Created
//
// +-------------------------------------------------------------

#include <Arduino.h>
#include <Wire.h>
#include <U8g2lib.h>
#include <Adafruit_SSD1306.h>
#include <adafruit_gfx.h>
// this set of libraries is for File manipulation
#include <SPI.h>
#include <SD.h>
// #include <TimeLib.h>

// library used to sort files when listing directory
// #include <iostream>
// #include <fstream>
// #include <vector>
// #include <algorithm>

// This will enable for the OLED screen to display information
// definition of OLED display SSD1306 for Arduino Mega SCA & SDL
// #define OLED_CLOCK 17 // SCA pin on Display = SCL on ESP32
// #define OLED_DATA 20  // SDL pin on display = SDA on ESP32
// U8G2 SSD1306 Driver here to run OLED Screen
// built constructor for the OLED function
// U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, OLED_CLOCK, OLED_DATA, U8X8_PIN_NONE); // This works but according to the function, it shouldn't
extern U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2;
// uint8_t oled_LineH = 0;
extern uint8_t oled_LineH;

// #define LED_BUILTIN 2 // pin for onboard LED or use LED_BUILTIN as the default location
// bool bLED = LOW;
extern bool bLED;

// ADAFRUIT SSD1306 Driver here to run animation
// NOTE: confirmed by I2C Scanner address for SSD1306 is 0x3c
// NOTE: const int SSD1306_addr = 0x3c;
// to initialilze the address of the OLED display
// #define SCREEN_I2C_ADDR 0x3C // or 0x3C
// #define SCREEN_WIDTH 128     // OLED display width, in pixels
// #define SCREEN_HEIGHT 64     // OLED display height, in pixels
// #define OLED_RST_PIN -1      // Reset pin (-1 if not available)
// Adafruit_SSD1306 display(128, 64, &Wire, OLED_RST_PIN);
extern Adafruit_SSD1306 display;

// adding the SD card reader
// #define SCK 17
// #define MISO 19
// #define MOSI 23
// #define CS 5

// variables for calling specific files
// extern const char *file0;
extern File file; // this instance is for normal file manipulation
// SPIClass spi = SPIClass(VSPI);

#ifndef CHAR_ARRAY_COMMON_H
#define CHAR_ARRAY_COMMON_H

const uint8_t height_width1 = 48;
const uint8_t height_width2 = 50;

template <typename T>
void CopyArrayStatusToDisplay(const T *array, uint8_t i)
{
    u8g2.clearBuffer();
    u8g2.home();

    u8g2.setCursor(3, oled_LineH * 2 + 2);
    u8g2.print(array[i].name);
    u8g2.setCursor(3, oled_LineH * 3 + 2);
    u8g2.print("has been written to");
    u8g2.setCursor(3, oled_LineH * 4 + 2);
    u8g2.print("the SD card.");
    u8g2.sendBuffer(); // Send it out
}; // end Displaying the action function

#endif // CHAR_ARRAY_COMMON_H
