#include "WifiHelper.h"

void WifiHelper::Start(const char* SSID_, const char* password_) {
    Serial.begin(9600);
    delay(10);

    Serial.println(); Serial.println();
    Serial.print("Connecting to "); Serial.println(SSID_);

    WiFi.begin(SSID_, password_);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println(""); Serial.println("WiFi connected");
}