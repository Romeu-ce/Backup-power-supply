#include "SensorsControl.h"
#include <Arduino.h>
#include <DHT.h>

DHT dht(22,DHT11) //22 - is the pin used

struct Result {
    float temp;
    float humidity;
    float voltage;
    float current;
};

Result control2(){
  delay(2000);

  float temp =dht.readTemperature(); // in celc
  float humidity =dht.readHumidity(); // in percent

  float X=(float)analogRead(32);
  float X1 = X- 112;    //datata error correction
  float Vin = ((float)analogRead(36)/4095)*3.29; //pin VP voltage readings
  float Ain = (X1/4095)*3.29;
  float Vr = Vin * 4.85;   //real velues
  float Ar= (Ain-1.1)/ 0.1; ////real velues
  voltage = Vr;
  current = Ar;


  return {temp,humidity,voltage,current};

}
