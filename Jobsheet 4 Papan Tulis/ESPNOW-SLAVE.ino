#include <esp_now.h>
#include <WiFi.h>
#include <CayenneMQTTESP32.h>
#define CAYENNE_PRINT Serial

typedef struct struct_message {
  int id;
  float temp;
  float hum;
} struct_message;
struct_message myData;
struct_message board1;
struct_message board2;
struct_message board3;
struct_message boardsStruct[3] = {board1, board2, board3};

const char* ssid = "8 makes 1 team";   // your network SSID (name)
const char* password = "akutolaper";   // your network password
const char* username = "ad528050-812d-11ed-b193-d9789b2af62b";
const char* mqtt_password = "423acb9c9638d64a9e20fd6bd30b9d21b156ee62";
const char* cliend_id = "b9831380-812d-11ed-b193-d9789b2af62b";
float temperature[3];
float humidity[3];

void OnDataRecv(const uint8_t * mac_addr, const uint8_t *incomingData, int len) {
  char macStr[18];
  Serial.print("Packet received from: ");
  snprintf(macStr, sizeof(macStr), "%02x:%02x:%02x:%02x:%02x:%02x",
           mac_addr[0], mac_addr[1], mac_addr[2], mac_addr[3], mac_addr[4],
           mac_addr[5]);
  Serial.println(macStr);
  memcpy(&myData, incomingData, sizeof(myData));
  boardsStruct[myData.id - 1].temp = myData.temp;
  boardsStruct[myData.id - 1].hum = myData.hum;
  Serial.printf("Board: %d \n", myData.id);
  Serial.printf("Temperature: %.2f \n", boardsStruct[myData.id - 1].temp);
  Serial.printf("Humidity: %.2f \n", boardsStruct[myData.id - 1].hum);
  Serial.println();
  temperature[myData.id - 1] = boardsStruct[myData.id - 1].temp;
  humidity[myData.id - 1] = boardsStruct[myData.id - 1].hum;
}

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }
  esp_now_register_recv_cb(OnDataRecv);
  Cayenne.begin(username, mqtt_password, cliend_id, ssid, password);
}

void loop() {
  Cayenne.loop();
  delay(1000);
}

CAYENNE_OUT_DEFAULT()
{
  Cayenne.virtualWrite(1, temperature[0], "temperature", "Celcius");
  Cayenne.virtualWrite(2, humidity[0], "humidity", "%");
  Cayenne.virtualWrite(3, temperature[1], "temperature", "Celcius");
  Cayenne.virtualWrite(4, humidity[1], "humidity", "%");
  Cayenne.virtualWrite(5, temperature[2], "temperature", "Celcius");
  Cayenne.virtualWrite(6, humidity[2], "humidity", "%");
}
