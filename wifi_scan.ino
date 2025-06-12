#include <ESP8266WiFi.h> 
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
Adafruit_SSD1306 display(128, 64, &Wire, -1);
void setup() {
Serial.begin(115200);
WiFi.mode(WIFI_STA);


 display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
   
    
}


void loop() {
int n = WiFi.scanNetworks();
  if (n == 0) {
    display.clearDisplay();
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(10, 10);
    display.println("no network found");
    display.display(); 
  } else {
    for (int i = 0; i < n; ++i) {
      display.clearDisplay();
      display.setTextColor(SSD1306_WHITE);
      display.setCursor(0, 0); 
      display.print("SSID: ");
      display.println(WiFi.SSID(i));
      display.print("RSSI: ");
      display.println(WiFi.RSSI(i));
      display.print("BSSID: ");
      display.println(WiFi.BSSIDstr(i));
      display.print("Channel: ");
      display.println(WiFi.channel(i));
      display.display(); 
      delay(7500);

  }
}
  delay(5000);
}
    
