//////////////////////Setup initial values for joysticks/////////////////////////////////////////
int pressed = -1;
int x = -1;
int y = -1;
int w = -1;
int z = -1;
int m = -1;
int n = -1;
int angle = 90;
////////////////////////////setup LCD I2C bus//////////////////////////////////////
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F, 16, 2);

//////////////////////////////Setup all servos///////////////////////////////////////
#include <Servo.h>
Servo base;
Servo BMain;
Servo TMain;
Servo TRotate;
Servo TMi;
Servo Grab;
//create an array to name the servo
String Snames[6] = {"Base", "Base Main", "Top Main", "Top Rotate", "Top Main", "Grab"};
/////////////////////////////setup the keypad/////////////////////////////////////////
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
  pinMode(37,OUTPUT);
  Serial.begin(9600);
  //////////////////////setup the pin for a pushbutton////////////////////////////////////////////
  pinMode(36, INPUT_PULLUP);
  ////////////////////////////setup the pins for joystick/////////////////////////////////
  pinMode(12, INPUT);
  digitalWrite(12, HIGH);
  pinMode(11, INPUT);
  digitalWrite(11, HIGH);
  pinMode(10, INPUT);
  digitalWrite(10, HIGH);
  ////////////////////////////setup pins for servos/////////////////////////////
  base.attach(22);
  BMain.attach(23);
  TMain.attach(24);
  TRotate.attach(25);
  TMi.attach(26);
  Grab.attach(27);
  base.write(90);
  BMain.write(90);
  TMain.write(90);
  TRotate.write(150);
  TMi.write(20);
  Grab.write(40);
  ////////////////////////////////setup the initial display for LCD///////////////////////////////////
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
if (digitalRead(36)==LOW){
  joystick();//controled by joystick
  digitalWrite(37,HIGH);
}
else{
  motorControl(); //controled by keypad
digitalWrite(37,LOW);
}
}
////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
int getservonames(char input) {  //Function to relate cases to servos' names
  int index=0;
  switch (input) {
    case 'A' : {
        index = 0;
        break;
      }
    case 'B': {
        index = 1;
         break;
      }
    case'C': {
        index = 2;
         break;
      }
    case'D' : {
        index = 3;
         break;
      }
    case'#' : {
        index = 4;
         break;
      }
    case'*': {
        index = 5;
         break;
      }
  }
  return index;
}


void motorControl() {  //Main part of keypad control
  int id=0;
  char forcase = kpd.getKey();
  id = getservonames(forcase);
  if (forcase != NO_KEY)
  {
    Serial.println(id);
    switch (forcase) {
      case 'A': {
          lcd.clear();
          
          lcd.setCursor(0, 0);
          lcd.print(Snames[id]);
          int a = kpd.waitForKey() - 48;
          int angle1 = map(a, 0, 9, 5, 179);
          constrain(angle1, 5, 179);
          base.write(angle1);
          lcd.setCursor(0, 1);
          lcd.print(angle1);
          break;
        }
      case 'B': {
          lcd.clear();
          
          lcd.setCursor(0, 0);
          lcd.print(Snames[id]);
          int b = kpd.waitForKey() - 48;
          int angle2 = map(b, 0, 9, 5, 179);
          constrain(angle2, 5, 179);
          BMain.write(angle2);
          lcd.setCursor(0, 1);
          lcd.print(angle2);
          break;
        }
      case 'C': {
          lcd.clear();
          
          lcd.setCursor(0, 0);
          lcd.print(Snames[id]);
          int c = kpd.waitForKey() - 48;
          int angle3 = map(c, 0, 9, 5, 179);
          constrain(angle3, 5, 179);
          TMain.write(angle3);
          lcd.setCursor(0, 1);
          lcd.print(angle3);
          break;
        }
      case 'D': {
          lcd.clear();
          
          lcd.setCursor(0, 0);
          lcd.print(Snames[id]);
          int d = kpd.waitForKey() - 48;
          int angle4 = map(d, 0, 9, 5, 179);
          constrain(angle4, 5, 179);
          TRotate.write(angle4);
          lcd.setCursor(0, 1);
          lcd.print(angle4);
          break;
        }
      case '#': {
          lcd.clear();
     
          lcd.setCursor(0, 0);
          lcd.print(Snames[id]);
          int e = kpd.waitForKey() - 48;
          int angle5 = map(e, 0, 9, 5, 179);
          constrain(angle5, 5, 179);
          TMi.write(angle5);
          lcd.setCursor(0, 1);
          lcd.print(angle5);
          break;
        }
      case '*': {
          lcd.clear();
        
          lcd.setCursor(0, 0);
          lcd.print(Snames[id]);
          int f = kpd.waitForKey() - 48;
          int angle6 = map(f, 0, 9, 5, 179);
          constrain(angle6, 5, 179);
          Grab.write(angle6);
          lcd.setCursor(0, 1);
          lcd.print(angle6);
          break;
        }
    }
  }
}

void joyControl(Servo servoname, int le) { //Joystick control
  if (le < -2 || le > 2) {
    angle = angle + le/abs(le);
    angle = constrain(angle, 1, 179);
    servoname.write(angle);
    delay(10);
  }
}

void joystick() {  //main part of joystick control
  x = map(analogRead(0), 0, 1023, -10, 10);
  y = map(analogRead(1), 0, 1023, -10, 10);
  w = map(analogRead(2), 0, 1023, -10, 10);
  z = map(analogRead(3), 0, 1023, -10, 10);
  m = map(analogRead(4), 0, 1023, -10, 10);
  n = map(analogRead(5), 0, 1023, -10, 10);
  joyControl(base, x);
  joyControl(BMain, y);
  joyControl(TMain, w);
  joyControl(TRotate, z);
  joyControl(TMi, m);
  joyControl(Grab, n);
}

