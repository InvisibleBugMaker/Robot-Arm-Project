

int pressed = -1;
int x = -1;
int y = -1;
int w = -1;
int z = -1;
int m = -1;
int n = -1;

#include <Servo.h>
Servo base;
Servo BMain;
Servo TMain;
Servo TRotate;
Servo TMi;
Servo Grab;

void setup() {
  pinMode(8, INPUT);
  digitalWrite(8, HIGH);
  pinMode(7, INPUT);
  digitalWrite(7, HIGH);
  pinMode(6, INPUT);
  digitalWrite(6, HIGH);

  Serial.begin(9600);

  base.attach(22);
  BMain.attach(23);
  TMain.attach(24);
  TRotate.attach(25);
  TMi.attach(26);
  Grab.attach(27);
  base.write(90);
  BMain.write(90);
  TMain.write(90);
  TRotate.write(90);
  TMi.write(90);
  Grab.write(90);
}

void loop() {
  int angle = 90;
  while (angle < 180 || angle > 0) {
    x = map(analogRead(0), 0, 1023, -10, 10);
    y = map(analogRead(1), 0, 1023, -10, 10);
    w = map(analogRead(2), 0, 1023, -10, 10);
    z = map(analogRead(3), 0, 1023, -10, 10);
    m = map(analogRead(4), 0, 1023, -10, 10);
    n = map(analogRead(5), 0, 1023, -10, 10);
    if (y < -2 || y > 2) {
      angle = angle + y ;
      angle = constrain(angle, 1, 179);
      Serial.println(angle);
      base.write(angle);
      delay(30);
    }
    if (x < -2 || x > 2) {
      angle = angle + x;
      angle = constrain(angle, 1, 179);
      Serial.println(angle);
      BMain.write(angle);
      delay(30);
    }
    if (z < -2 || z > 2) {
      angle = angle + z;
      angle = constrain(angle, 1, 179);
      Serial.println(angle);
      TMain.write(angle);
      delay(30);
    }
    if (w < -2 || w > 2) {
      angle = angle + w;
      angle = constrain(angle, 1, 179);
      Serial.println(angle);
      TRotate.write(angle);
      delay(30);
    }
    if (m < -2 || m > 2) {
      angle = angle + m;
      angle = constrain(angle, 1, 179);
      Serial.println(angle);
      TMi.write(angle);
      delay(30);
    }
    if (n < -2 || n > 2) {
      angle = angle + n;
      angle = constrain(angle, 1, 179);
      Serial.println(angle);
      Grab.write(angle);
      delay(30);
    }
  }
}
