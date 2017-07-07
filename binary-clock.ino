#include <DS3231.h>
#include <Wire.h>

DS3231 Clock;
bool Century=false;
bool h12 = true;
bool PM;

byte hour, minute;

int m1 = 12;  
int m2 = 11;  
int m4 = 10;  
int m8 = 9;  
int m16 = 8;  
int m32 = 7;  
int h1 = 5;  
int h2 = 4;  
int h4 = 3;  
int h8 = 2;  

void setup() {
  Wire.begin();
  
  pinMode(m1, OUTPUT);
  pinMode(m2, OUTPUT);
  pinMode(m4, OUTPUT);
  pinMode(m8, OUTPUT);
  pinMode(m16, OUTPUT);
  pinMode(m32, OUTPUT);

  pinMode(h1, OUTPUT);
  pinMode(h2, OUTPUT);
  pinMode(h4, OUTPUT);
  pinMode(h8, OUTPUT);

  digitalWrite(m1, HIGH);
  digitalWrite(m2, HIGH);
  digitalWrite(m4, HIGH);
  digitalWrite(m8, HIGH);
  digitalWrite(m16, HIGH);
  digitalWrite(m32, HIGH);

  digitalWrite(h1, HIGH);
  digitalWrite(h2, HIGH);
  digitalWrite(h4, HIGH);
  digitalWrite(h8, HIGH);
}

void loop() {
  delay(1000);

  minute=Clock.getMinute();
  hour=Clock.getHour(h12, PM)%12;

  output();
}

void output() {
  digitalWrite(m1, (1 & minute) ? HIGH : LOW);
  digitalWrite(m2, (2 & minute) ? HIGH : LOW);
  digitalWrite(m4, (4 & minute) ? HIGH : LOW);
  digitalWrite(m8, (8 & minute) ? HIGH : LOW);
  digitalWrite(m16, (16 & minute) ? HIGH : LOW);
  digitalWrite(m32, (32 & minute) ? HIGH : LOW);

  digitalWrite(h1, (1 & hour) ? HIGH : LOW);
  digitalWrite(h2, (2 & hour) ? HIGH : LOW);
  digitalWrite(h4, (4 & hour) ? HIGH : LOW);
  digitalWrite(h8, (8 & hour) ? HIGH : LOW);
}


