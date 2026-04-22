#include "OLED.h"
#include <Arduino.h>
#include "OLED.h"
#include <Wire.h>
#include <U8g2lib.h>

U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, U8X8_PIN_NONE);


bool animationStat = false;

void screen(float a,float b,float c) {
  if (!screen_active) return;
  u8g2.begin();
  a=12.2,b=14.4,c=90.9;
  char line11[20];
  char line22[20];
  char line33[20];
  dtostrf(a, 4, 2, line11); 
  dtostrf(b, 4, 2, line22);
  dtostrf(c, 4, 2, line33); 
  const char* line1 = "Temperature";
  const char* line2 = "Humidity";
  const char* line3 = "Charge%";
  u8g2.setFont(u8g2_font_5x8_tr);
  if (!animationStat){
  // Fade-in
  for (int i = 0; i < 3; i++) {
    u8g2.clearBuffer();
    u8g2.sendBuffer();
    delay(100);
  }

  // Typing animation
  String current1 = "";
  String current2 = "";
  String current3 = "";

  // --- Animate first line ---
  for (int i = 0; i < strlen(line1); i++) {
    current1 += line1[i];
    u8g2.clearBuffer();
    u8g2.drawStr(10, 12, current1.c_str());
    u8g2.drawStr(70, 12, line11);
    u8g2.sendBuffer();
    delay(100);
  }

  delay(400);

  // --- Animate second line ---
  for (int i = 0; i < strlen(line2); i++) {
    current2 += line2[i];
    u8g2.clearBuffer();
    u8g2.drawStr(10, 12, line1);
    u8g2.drawStr(70, 12, line11);
    u8g2.drawStr(10, 24, current2.c_str());
    u8g2.drawStr(70, 24, line22);
    u8g2.sendBuffer();
    delay(120);
  }
  delay(1000);
  //third line
  for (int i = 0; i < strlen(line3); i++) {
    current3 += line3[i];
    u8g2.clearBuffer();
    u8g2.drawStr(10, 12,line1);
    u8g2.drawStr(70, 12, line11);
    u8g2.drawStr(10, 24,line2);
    u8g2.drawStr(70, 24, line22);
    u8g2.drawStr(10, 36, current3.c_str());
    u8g2.drawStr(70, 36, line33);
    u8g2.sendBuffer();
    delay(140);
    animationStat = true;
  }
  delay(500);
  }

  u8g2.firstPage();
  do {
    u8g2.drawStr(10, 12,line1);
    u8g2.drawStr(70, 12, line11);
    u8g2.drawStr(10, 24,line2);
    u8g2.drawStr(70, 24, line22);
    u8g2.drawStr(10, 36, line3);
    u8g2.drawStr(70, 36, line33);
  } while (u8g2.nextPage());

  

  delay(1000);
  
}

