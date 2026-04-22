#include "SensorsControl.h"
#include <Arduino.h>
#include <DHT.h>

DHT dht(27,DHT11); //22 - is the pin used


Result control2(){
  delay(2000);
  dht.begin();

  float temp =dht.readTemperature(); // in celc
  float humidity =dht.readHumidity(); // in percent

  float X=(float)analogRead(34); //current readings
  //float X1 = X- 112;    //datata error correction
  float Vin = ((float)analogRead(36)/4095)*3.29; //pin VP voltage readings
  float Ai = (X/4095)*3.29;
  float Ain =Ai/2.210526;
  float Vr = Vin * 11;   //real velues ( 4.85)
  float Ar= (Ain-1.1)/ 0.1; //real velues
  float voltage = Vr;
  float current = Ar;


  return {temp,humidity,voltage,current};

}
