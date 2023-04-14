#include<Servo.h>
Servo x,y,c;
#define S 6
#define MA1 7
#define MA2 8
#define MB1 9
#define MB2 10
int Ax=90, Ay=0,Ac=0;
char data;
void setup() {
  pinMode(S,OUTPUT);
  pinMode(MA1,OUTPUT);
  pinMode(MA2,OUTPUT);
  pinMode(MB1,OUTPUT);
  pinMode(MB2,OUTPUT);

  x.attach(2);
  y.attach(3);
  c.attach(4);

  x.write(Ax);
  y.write(Ay);
  c.write(Ac);

  Serial.begin(9600);
}

void loop() {
  if(Serial.available()>0){
    data = Serial.read();
  }

  if(data == 'F'){
    forward();
  }
  else if(data == 'B'){
    backward();
  }
  else if(data == 'R'){
    right();
  }
  else if (data == 'L'){
    left();
  }
  else if(data == '0'){
    stop();
  }
  else if (data == 'X' && Ax<120){
    Ax+=1;
    x.write(Ax);
  }
  else if(data == 'x' && Ax>0){
    Ax-=1;
    x.write(Ax);
  }
  else if ( data == 'Y' && Ay<90){
    Ay+=1;
    y.write(Ay);
  }
  else if ( data == 'y' && Ay>0){
    Ay-=1;
    y.write(Ay);
  }
  else if (data == 'C' && Ac<60){
    Ac+=1;
    c.write(Ac);
  }
  else if (data == 'c' && Ac>0){
    Ac-=1;
    c.write(Ac);
  }
}

void forward(){
  analogWrite(S,255);
  digitalWrite(MA1, HIGH);
  digitalWrite(MA2, LOW);
  digitalWrite(MB1, HIGH);
  digitalWrite(MB2, LOW);
}
void backward(){
  analogWrite(S,255);
  digitalWrite(MA1, LOW);
  digitalWrite(MA2, HIGH);
  digitalWrite(MB1, LOW);
  digitalWrite(MB2, HIGH);
}
void right(){
  analogWrite(S,255);
  digitalWrite(MA1, HIGH);
  digitalWrite(MA2, LOW);
  digitalWrite(MB1, LOW);
  digitalWrite(MB2, LOW);
}
void left(){
  analogWrite(S,255);
  digitalWrite(MA1, LOW);
  digitalWrite(MA2, LOW);
  digitalWrite(MB1, HIGH);
  digitalWrite(MB2, LOW);
}
void stop(){
  analogWrite(S,0);
  digitalWrite(MA1, LOW);
  digitalWrite(MA2, LOW);
  digitalWrite(MB1, LOW);
  digitalWrite(MB2, LOW);
}
