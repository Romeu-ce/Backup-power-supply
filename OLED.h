#ifndef OLED
#define OLED

extern bool screen_active;
extern unsigned long screen_start;
extern const unsigned long SCREEN_DURATION; // 10 seconds

void screen(float a,float b,float c);
#endif
