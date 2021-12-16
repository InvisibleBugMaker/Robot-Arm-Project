int pressed = -1;
int x = -1;
int y = -1;
int w = -1;
int z = -1;
int m = -1;
int n = -1;
//////////////////////////////////////////////////////////////////
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F, 16, 2);
/////////////////////////////////////////////////////////////////////
#include <Servo.h>
Servo base;
Servo BMain;
Servo TMain;
Servo TRotate;
Servo TMi;
Servo Grab;
String Snames[6] = {"Base", "Base Main", "Top Main", "Top Rotate", "Top Main", "Grab"};
//////////////////////////////////////////////////////////////////////
#include <Keypad.h>
char keymap[4][4] =
{
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte rPins[4] = {9, 8, 7, 6};
byte cPins[4] = {5, 4, 3, 2};
Keypad kpd = Keypad(makeKeymap(keymap), rPins, cPins, 4, 4);
/////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
void setup() {
  Serial.begin(9600);
  pinMode(36, INPUT_PULLUP);
  /////////////////////////////////////////////////////////////
  pinMode(12, INPUT);
  digitalWrite(8, HIGH);
  pinMode(11, INPUT);
  digitalWrite(7, HIGH);
  pinMode(10, INPUT);
  digitalWrite(6, HIGH);
  /////////////////////////////////////////////////////////
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
  ///////////////////////////////////////////////////////////////////
  lcd.init();
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Angle");
  lcd.setCursor(0, 1);
  lcd.print("########");
}
//////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////
void loop() {
  char forcase = kpd.getKey();
  if (forcase != NO_KEY)
  {
    switch (forcase) {
      case 'A': {
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Base");
          int a = kpd.waitForKey() - 48;
          int angle1 = map(a, 0, 9, 0, 180);
          base.write(angle1);
          lcd.setCursor(0, 1);
          lcd.print(angle1);
          break;
        }
      case 'B': {
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Base Main");
          int b = kpd.waitForKey() - 48;
          int angle2 = map(b, 0, 9, 0, 180);
          BMain.write(angle2);
          lcd.setCursor(0, 1);
          lcd.print(angle2);
          break;
        }
      case 'C': {
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Top Main");
          int c = kpd.waitForKey() - 48;
          int angle3 = map(c, 0, 9, 0, 180);
          TMain.write(angle3);
          lcd.setCursor(0, 1);
          lcd.print(angle3);
          break;
        }
      case 'D': {
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Top Rotate");
          int d = kpd.waitForKey() - 48;
          int angle4 = map(d, 0, 9, 0, 180);
          TRotate.write(angle4);
          lcd.setCursor(0, 1);
          lcd.print(angle4);
          break;
        }
      case '#': {
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Top Min");
          int e = kpd.waitForKey() - 48;
          int angle5 = map(e, 0, 9, 0, 180);
          TMi.write(angle5);
          lcd.setCursor(0, 1);
          lcd.print(angle5);
          break;
        }
      case '*': {
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Grab");
          int f = kpd.waitForKey() - 48;
          int angle6 = map(f, 0, 9, 0, 180);
          Grab.write(angle6);
          lcd.setCursor(0, 1);
          lcd.print(angle6);
          break;
        }
    }
  }
  /*int angle = 90;
    while (angle < 180 && angle > 0) {
    x = map(analogRead(0), 0, 1023, -10, 10);
    y = map(analogRead(1), 0, 1023, -10, 10);
    w = map(analogRead(2), 0, 1023, -10, 10);
    z = map(analogRead(3), 0, 1023, -10, 10);
    m = map(analogRead(6), 0, 1023, -10, 10);
    n = map(analogRead(7), 0, 1023, -10, 10);
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
    }*/
}
int getservonames(char input) {
  int index;
  switch (input) {
    case 'A' : {
        index = 0;
      }
    case 'B': {
        index = 1;
      }
    case'C': {
        index = 2;
      }
    case'D' : {
        index = 3;
      }
    case'#' : {
        index = 4;
      }
    case'*': {
        index = 5;
      }
  }
  return index;
}



void motorControl() {
  int id;
  char forcase = kpd.getKey();
  if (forcase != NO_KEY)
  {
    switch (forcase) {
      case 'A': {
          lcd.clear();
          id=getservonames(forcase);
          lcd.setCursor(0, 0);
          lcd.print(Snames[id]);
          int a = kpd.waitForKey() - 48;
          int angle1 = map(a, 0, 9, 0, 180);
          base.write(angle1);
          lcd.setCursor(0, 1);
          lcd.print(angle1);
          break;
        }
      case 'B': {
          lcd.clear();
          id=getservonames(forcase);
          lcd.setCursor(0, 0);
          lcd.print(Snames[id]);
          int b = kpd.waitForKey() - 48;
          int angle2 = map(b, 0, 9, 0, 180);
          BMain.write(angle2);
          lcd.setCursor(0, 1);
          lcd.print(angle2);
          break;
        }
      case 'C': {
          lcd.clear();
          id=getservonames(forcase);
          lcd.setCursor(0, 0);
          lcd.print(Snames[id]);
          int c = kpd.waitForKey() - 48;
          int angle3 = map(c, 0, 9, 0, 180);
          TMain.write(angle3);
          lcd.setCursor(0, 1);
          lcd.print(angle3);
          break;
        }
      case 'D': {
          lcd.clear();
          id=getservonames(forcase);
          lcd.setCursor(0, 0);
          lcd.print(Snames[id]);
          int d = kpd.waitForKey() - 48;
          int angle4 = map(d, 0, 9, 0, 180);
          TRotate.write(angle4);
          lcd.setCursor(0, 1);
          lcd.print(angle4);
          break;
        }
      case '#': {
          lcd.clear();
          id=getservonames(forcase);
          lcd.setCursor(0, 0);
          lcd.print(Snames[id]);
          int e = kpd.waitForKey() - 48;
          int angle5 = map(e, 0, 9, 0, 180);
          TMi.write(angle5);
          lcd.setCursor(0, 1);
          lcd.print(angle5);
          break;
        }
      case '*': {
          lcd.clear();
          id=getservonames(forcase);
          lcd.setCursor(0, 0);
          lcd.print(Snames[id]);
          int f = kpd.waitForKey() - 48;
          int angle6 = map(f, 0, 9, 0, 180);
          Grab.write(angle6);
          lcd.setCursor(0, 1);
          lcd.print(angle6);
          break;
        }
    }
  }
}

void joyControl(Servo servoname,int le) {
  if (le < -2 || le > 2) {
    int angle = 90;
    angle = angle + le;
    angle = constrain(angle, 1, 179);
    Serial.println(angle);
    servoname.write(angle);
    delay(30);
  }
}

void joystick() {
  int angle = 90;
  while (angle < 180 && angle > 0) {
    x = map(analogRead(0), 0, 1023, -10, 10);
    y = map(analogRead(1), 0, 1023, -10, 10);
    w = map(analogRead(2), 0, 1023, -10, 10);
    z = map(analogRead(3), 0, 1023, -10, 10);
    m = map(analogRead(6), 0, 1023, -10, 10);
    n = map(analogRead(7), 0, 1023, -10, 10);
    joyControl(base,x);
    joyControl(BMain,y);
    joyControl(TMain,w);
    joyControl(TRotate,z);
    joyControl(TMi,m);
    joyControl(Grab,n);
  }
}

