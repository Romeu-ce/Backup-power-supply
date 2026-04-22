#include "BatteryControl.h"
#include "SensorsControl.h"
#include "OLED.h"
#include <DHT.h>
#include <Wire.h>
#include <U8g2lib.h>


bool screen_active = false;
unsigned long screen_start = 0;
const unsigned long SCREEN_DURATION = 10000; // 10 seconds

int l =12;
float a,b,c,d;
int batCap;
void setup() {
    Serial.begin(115200);
    analogReadResolution(12); // 0–4095
    pinMode(2, OUTPUT); //battery
    pinMode(35, INPUT); //net Voltage
    pinMode(4, OUTPUT); //battery
    pinMode(14, INPUT); //pin for sign
    pinMode(l, INPUT); //button for screen
    analogSetPinAttenuation(34, ADC_11db);  //current readings
    analogSetPinAttenuation(36, ADC_11db);  //voltage readings
}

void loop() {

  Result r = control2();
  a = r.temp;
  b = r.humidity;
  c = r.voltage;
  d = r.current;

  control1(c,d);
  batCap = control1(c,d);

  if (digitalRead(l)== HIGH) {
    screen_active = true;
    screen_start = millis();
    screen(a,b,c); // your init/start call
  }

  if (screen_active) {
    if (millis()- screen_start>= SCREEN_DURATION) {
        screen_active =false;
       screen(a,b,c); // turn off / clear screen
    }
  } 

}
