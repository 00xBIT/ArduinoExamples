#include <SoftwareSerial.h>

SoftwareSerial SIM800(8, 9);        // 8 - RX Arduino (TX SIM800L), 9 - TX Arduino (RX SIM800L)
void setup() {
  Serial.begin(9600);               // —корость обмена данными с компьютером
  Serial.println("Start!");
  SIM800.begin(9600);               // —корость обмена данными с модемом
  SIM800.println("AT");
}

void loop() {
  if (SIM800.available())           // ќжидаем прихода данных (ответа) от модема...
    Serial.write(SIM800.read());    // ...и выводим их в Serial
  if (Serial.available())           // ќжидаем команды по Serial...
    SIM800.write(Serial.read());    // ...и отправл€ем полученную команду модему
}