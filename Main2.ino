#include "BatteryControl.h"
#include "SensorsControl.h"
#include <DHT.h>
#include <Wire.h>
#include <U8g2lib.h>

float a,b,c,d;
int batCap;
void setup() {
    Serial.begin(115200);
    dht.begin();
    u8g2.begin();
    pinMode(2, OUTPUT);
    pinMode(35, INPUT);
    pinMode(4, OUTPUT);
    pinMode(1,INPUT); //pin fot voltage
    pinMode(2,INPUT); //pin for current
    pinMode(14, INPUT); //pin for sign
    analogSetPinAttenuation(32, ADC_11db);  //current readings
    analogSetPinAttenuation(36, ADC_11db);  //voltage readings
}

void loop() {

  Result r = control2();
  a = r.temp;
  b = r.humidity;
  c = r.voltage;
  d = r.current;

  control1();
  batCap = control1(c,d)
}
