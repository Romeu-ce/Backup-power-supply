#include "BATTERYcontrol.h"
#include<Arduino.h>

int netVoltage = 0; //checks if there is power in the external network
static int battaryCapacity = 220000; //maximum battary capacity
int usedEnergy = 0, usedPower = 0,chargEnergy=0;
int usedTimeSeconds1 = 0,usedTimeSeconds = 0;
bool timerRunning = false;
int batVolt = 0,batCur = 0;
//int a,b; //pins for voltage and current
uint32_t now=0,lastTime = 0, usedTime0 = 0,usedTime1 = 0,usedTime2= 0;

int control1(){
  
  netVoltage = digitalRead(35);
  Serial.print("Pin value: ");
  Serial.println(netVoltage);

  now = millis();
  usedTime0 = (now - lastTime);
  lastTime = now;
  usedTimeSeconds = usedTime0/1000;
  usedTimeSeconds1 = usedTime0/1000;


  if(netVoltage == HIGH && battaryCapacity<220000 ){  //there is electricity , charge the battery
    digitalWrite(2, HIGH); //turn on the charging module
    digitalWrite(4, LOW); 
    batVolt = 15 ;//digitalRead(a);
    batCur = 7; //digitalRead(b);
    usedTime2+=usedTime0; // turn of the battery
  }
  else if(netVoltage == LOW) { //discharge the battery
    digitalWrite(2, LOW);  //there is no electrycity, use battery
    digitalWrite(4,HIGH); //turn of charging module

    batVolt = 12 ;//digitalRead(a);
    batCur = 5; //digitalRead(b); //replace "//" 
    usedTime1+=usedTime0;
  }
  else if(netVoltage == HIGH && battaryCapacity>200000 ) { //stop charging
    digitalWrite(2, LOW);  //
    digitalWrite(4,LOW); //turn of charging module
  }
  usedTimeSeconds = usedTime1/1000;
  usedTimeSeconds1 = usedTime2/1000;
  usedPower = batVolt * batCur;
  usedEnergy= usedPower * usedTimeSeconds;
  chargEnergy=usedPower * usedTimeSeconds1;
  Serial.print("used energy: "); //tests
  Serial.println(usedEnergy);
  Serial.print("charged energy: ");
  Serial.println(chargEnergy);

  if(netVoltage == HIGH){  
    battaryCapacity+=chargEnergy;
  }
  if(netVoltage == LOW){
     battaryCapacity-=usedEnergy;  
  }
  Serial.print("batt capp: ");  //test
  Serial.println(battaryCapacity);
  delay(300);
  return battaryCapacity;
}