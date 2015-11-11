/*
 *  This sketch demonstrates how to scan WiFi networks. 
 *  The API is almost the same as with the WiFi Shield library, 
 *  the most obvious difference being the different file you need to include:
 */
#include "ESP8266WiFi.h"

void setup() {
  Serial.begin(115200);

  // Set WiFi to station mode and disconnect from an AP if it was previously connected
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);

  Serial.println("Setup done");
}

void loop() {
  Serial.println("scan start");
  unsigned long startTime = millis();

  // WiFi.scanNetworks will return the number of networks found
  int n = WiFi.scanNetworks();
  
  unsigned long endTime = millis();
  unsigned long duration = endTime - startTime;
  
  Serial.printf( "scan done: %d milliseconds\n", duration );
  if (n == 0)
    Serial.println("no networks found");
  else
  {
    Serial.print(n);
    Serial.println(" networks found");
    for (int i = 0; i < n; ++i)
    {
      Serial.printf(
          "{\"macAddress\":\"%s\",\"channel\":%d,\"signalStrength\":%d},\n",
          WiFi.BSSIDstr(i).c_str(),
          WiFi.channel(i),
          WiFi.RSSI(i)
      );
          
      delay(10);
    }
  }
  Serial.println("");

  // Wait a bit before scanning again
  delay(5000);
}
