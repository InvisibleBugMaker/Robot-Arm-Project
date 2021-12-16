#include <Servo.h>
Servo base;
Servo BMain;
Servo TMain;
Servo TRotate;
Servo TMi;
Servo Grab;

void setup() {
  base.attach(22);
  
  BMain.attach(23);
  TMain.attach(24);
  TRotate.attach(25);
  TMi.attach(26);
  Grab.attach(27);
  
  base.write(90);
  delay(300);
  BMain.write(90);
  delay(300);
  TMain.write(90);
  delay(300);
  TRotate.write(150);
  delay(300);
  TMi.write(20);
  delay(300);
  Grab.write(10);
  delay(3000);
  for(int i=90;i>0;i--){
    base.write(i);
    delay(10);
  }
  for(int i=150;i>50;i--){
    TRotate.write(i);
    delay(10);
  }
  for(int i=90;i<135;i++){
    BMain.write(i);
    delay(10);
  }
  for(int i=80;i>30;i--){
    TMain.write(i);
    delay(10);
  }
  
  for(int i=20;i<40;i++){
    TMi.write(i);
    delay(10);
  }
  for(int i=10;i<35;i++){
    Grab.write(i);
    delay(10);
  }
  for(int i=135;i>90;i--){
    BMain.write(i);
    delay(10);
  }
  for(int i=40;i<75;i++){
    TMi.write(i);
    delay(10);
  }
  for(int i=0;i<80;i++){
    base.write(i);
    delay(5);
  }
  delay(1000);
  for(int i=35;i>10;i--){
    Grab.write(i);
    delay(10);
  }
  }

void loop(){
  /*delay(1000);
  for(int i=90;i>0;i--){
    base.write(i);
    delay(20);
  }
  for(int i=90;i<135;i++){
    BMain.write(i);
    delay(20);
  }
  for(int i=80;i>30;i--){
    TMain.write(i);
    delay(20);
  }
  for(int i=150;i>50;i--){
    TRotate.write(i);
    delay(20);
  }
  for(int i=20;i<40;i++){
    TMi.write(i);
    delay(20);
  }
  for(int i=40;i>30;i--){
    Grab.write(i);
    delay(20);
  }
  delay(1000000)*/
}

    

