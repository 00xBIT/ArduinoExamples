#include <SoftwareSerial.h>

SoftwareSerial SIM800(8, 9);        // 8 - RX Arduino (TX SIM800L), 9 - TX Arduino (RX SIM800L)
void setup() {
  Serial.begin(9600);               // �������� ������ ������� � �����������
  Serial.println("Start!");
  SIM800.begin(9600);               // �������� ������ ������� � �������
  SIM800.println("AT");
}

void loop() {
  if (SIM800.available())           // ������� ������� ������ (������) �� ������...
    Serial.write(SIM800.read());    // ...� ������� �� � Serial
  if (Serial.available())           // ������� ������� �� Serial...
    SIM800.write(Serial.read());    // ...� ���������� ���������� ������� ������
}