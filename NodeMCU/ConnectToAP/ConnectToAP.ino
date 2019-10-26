#include <ESP8266WiFi.h>

void setup() {
  Serial.begin(9600);
  Serial.println();
  WiFi.begin("AP", "password");
  Serial.print("connecting ");

  while(WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  
  Serial.println("connected");
  Serial.println(WiFi.localIP()); //вывод на монитор порта динамического (выданного WiFi маршрутизатором) IP адреса esp8266
  Serial.print(WiFi.RSSI()); //вывод на монитор уровня WiFi сигнала в децибелах 
}

void loop() {
  Serial.print(WiFi.RSSI());
}
