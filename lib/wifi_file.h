// If I had the RTC module installed, I would use this code to get the time from the internet and then save it to the RTC module.
// then I could save files with the current time as the name.

#include <Arduino.h>
#include <WiFi.h>
#include "time.h"

const char *ssid = "your_SSID";
const char *password = "your_PASSWORD";
const char *ntpServer = "pool.ntp.org";
const long gmtOffset_sec = 3600;
const int daylightOffset_sec = 3600;

void setup()
{
    Serial.begin(115200);

    // connect to WiFi
    Serial.printf("Connecting to %s ", ssid);
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }
    Serial.println(" CONNECTED");

    // init and get the time
    configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
    printLocalTime();

    // disconnect WiFi as it's no longer needed
    WiFi.disconnect(true);
    WiFi.mode(WIFI_OFF);
}

void loop()
{
    delay(1000);
    printLocalTime();
}

void printLocalTime()
{
    struct tm timeinfo;
    if (!getLocalTime(&timeinfo))
    {
        Serial.println("Failed to obtain time");
        return;
    }
    Serial.println(&timeinfo, "%A, %B %d %Y %H:%M:%S");
}