#include <CayenneMQTTESP32.h>
#include <WiFi.h>
#include "DHT.h"
#define DHTPIN 4
#define DHTTYPE DHT11
#define CAYENNE_PRINT Serial 

const char* ssid = "8 makes 1 team";   // your network SSID (name)
const char* password = "akutolaper";   // your network password
const char* username = "ad528050-812d-11ed-b193-d9789b2af62b";
const char* mqtt_password = "423acb9c9638d64a9e20fd6bd30b9d21b156ee62";
const char* cliend_id = "b9831380-812d-11ed-b193-d9789b2af62b";
const int ledPin = 16;

// Variable to hold readings
float temperature;
float humidity;

WiFiClient  client;
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Cayenne.begin(username, mqtt_password, cliend_id, ssid, password);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);
  dht.begin();  //Initialize DHT
}
  
void loop() {
  // Get a new temperature reading
  humidity = dht.readHumidity();
  temperature = dht.readTemperature();
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }
  
  Cayenne.loop();
  delay(100);
}

CAYENNE_OUT(1)
{
  //  Cayenne.vritualWrite(0, millis());
  CAYENNE_LOG("Send data for Channel %d Suhu %f C", 1, temperature);
  Cayenne.virtualWrite(1,temperature,"temperature","c");
}

CAYENNE_OUT(2)
{
  CAYENNE_LOG("Send data for Channel %d Hum %f %", 2, humidity);
  Cayenne.virtualWrite(2,humidity,"humidity","p");
}

CAYENNE_IN(3)
{
  digitalWrite(ledPin, !getValue.asInt());  // to get the value from the website
}
