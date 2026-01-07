#include <TinyGPSPlus.h>

TinyGPSPlus gps;
HardwareSerial GPS(1);

void setup() {
  Serial.begin(115200);
  GPS.begin(9600, SERIAL_8N1, 34, -1);  // RX=34, TX unused

  Serial.println("GPS test starting...");
}

void loop() {
  while (GPS.available()) {
    gps.encode(GPS.read());
  }

  if (gps.location.isUpdated()) {
    Serial.print("Lat: ");
    Serial.println(gps.location.lat(), 6);
    Serial.print("Lon: ");
    Serial.println(gps.location.lng(), 6);
    Serial.print("Time: ");
    Serial.print(gps.time.hour());
    Serial.print(":");
    Serial.print(gps.time.minute());
    Serial.print(":");
    Serial.println(gps.time.second());
    Serial.println("--------------------");
  }
}
