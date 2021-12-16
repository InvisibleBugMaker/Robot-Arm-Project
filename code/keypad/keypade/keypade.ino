#include <Keypad.h>

//we will definne the key map as on the key pad:

char keymap[4][4]=
{
{'1', '2', '3','A'},
{'4', '5', '6','B'},
{'7', '8', '9','C'},
{'*', '0', '#','D'}
};

byte rPins[4]= {9,8,7,6};
byte cPins[4]= {5,4,3,2};


Keypad kpd= Keypad(makeKeymap(keymap), rPins, cPins, 4, 4);

void setup()
{
     Serial.begin(9600);  // initializing serail monitor
}

void loop()
{
     char keypressed = kpd.getKey();
     if (keypressed != NO_KEY)
     { 
          Serial.println(keypressed);
     }
}
