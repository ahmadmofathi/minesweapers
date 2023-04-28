#include <Adafruit_NeoPixel.h>
Adafruit_NeoPixel Neo = Adafruit_NeoPixel(16,A1,NEO_GRB+NEO_KHZ800); 
char value;
void setup() {
  Neo.begin();
  Neo.setBrightness(50);
  Serial.begin(9600);
}

void loop() {
  if(Serial.available()>0){
    value = Serial.read();
  }

  if(value=='i'){
    Increasing(100,0,120);
  }
  else if(value == 'd'){
    Decreasing(100,0,120);
  }
  else if(value == 's'){
    snake(100,0,120);
  }
}

void Increasing(int R,int G,int B){
  for(int i=0;i<=15;i++){
    Neo.setPixelColor(i,R,G,B);
    Neo.show();
    delay(100);
  }
  delay(500);
  Neo.clear();
}

void Decreasing(int R,int G,int B){
  for(int i=15;i>=0;i--){
    Neo.setPixelColor(i,R,G,B);
    Neo.show();
    delay(100);
  }
  delay(500);
  Neo.clear();
}

void snake(int R,int G,int B){
  for(int i=0;i<=19;i++){
    Neo.setPixelColor(i,R,G,B);
    Neo.setPixelColor(i-4,0,0,0);
    Neo.show();
    delay(200);
  }
  delay(500);
  Neo.clear();
}
