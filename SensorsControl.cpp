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
 //std::ostream& operator<<(std::ostream& os, const Result& r) {
 //   return os << "sum: " << r.sum << ", product: " << r.product;
//}

Result control2(){
  //dht.begin();
  delay(2000);

  float temp =dht.readTemperature(); // in celc
  float humidity =dht.readHumidity(); // in percent

  return {temp,humidity};

}