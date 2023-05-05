#include <Adafruit_NeoPixel.h>
Adafruit_NeoPixel Neo = Adafruit_NeoPixel(16,A1,NEO_GRB+NEO_KHZ800);
int R=0,G=0,B=0;
char value;
void setup() {
  Neo.begin();
  Neo.setBrightness(255);
  Serial.begin(9600);
}

void loop() {
  if(Serial.available()>0){
    value = Serial.read();
  }
  if(value=='R'){
    red();
  }
  else if(value=='B'){
    blue();
  }
  else if (value=='G'){
    green();
  }
  else if(value == 'P'){
    purple();
  }
  else if(value == 'I'){
    inc();
  }
  else if(value=='D'){
    dec();
  }
  else if(value=='S'){
    snake();
  }
}

void red(){
  R=255;
  G=0;
  B=0;
}
void blue(){
  R=0;
  G=0;
  B=255;
}
void green(){
  R=0;
  G=255;
  B=0;
}
void purple(){
  R=147;
  G=0;
  B=200;
}
void inc(){
  for(int i=0;i<16;i++){
    Neo.setPixelColor(i,R,G,B);
    Neo.show();
    delay(100);
  }
  Neo.clear();
}
void dec(){
  for(int i=0;i<16;i++){
    Neo.setPixelColor(i,R,G,B);
    Neo.show();
    delay(100);
  }
  for(int i =15;i>=0;i--){
    Neo.setPixelColor(i,0,0,0);
    Neo.show();
    delay(100);
  }
  Neo.clear();
}
void snake(){
  for(int i=0;i<20;i++){
    Neo.setPixelColor(i,R,G,B);
    Neo.setPixelColor(i-4,0,0,0);
    Neo.show();
    delay(100);
  }
}
