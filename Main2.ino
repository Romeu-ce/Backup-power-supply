#include "BatteryControl.h"
#include "SensorsControl.h"
#include <DHT.h>
#include <Wire.h>
#include <U8g2lib.h>

float a,b;

void setup() {
    Serial.begin(115200);
    dht.begin();
    u8g2.begin();
    pinMode(2, OUTPUT);
    pinMode(35, INPUT);
    pinMode(4, OUTPUT);
    pinMode(1,INPUT); //pin fot voltage
    pinMode(2,INPUT); //pin for current
}

void loop() {

  control1();

  Result r = control2();
  a = r.temp;
  b = r.humidity;
}
