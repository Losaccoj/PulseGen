/* PulseGen 2017
Written by Justin Losacco
MIT-licensed, freely available on GitHub */

// include the library code:
#include <LiquidCrystal.h>
#include <Bounce.h>
#include <Key.h>
#include <Keypad.h>

//Keypad initialization stuff
const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {23, 22, 21, 20}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {19, 18, 17, 16}; //connect to the column pinouts of the keypad
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

// initialize library by pairinig LCD pin w/ Teensy pin
const int rs = 10, en = 9, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// Define stim-associated pins on Teensy:
const int trig1 = 6; //input trigger from behavioral PC. (AKA in_trig)
const int trig2 = 7; //button on PulseGen
const int TTL1 = 29; //output TTL trigger to laser
const int LED1 = 8; //output LED on PulseGen
Bounce in_trig1 = Bounce(trig1, 10);     //Debounce
Bounce in_trig2 = Bounce(trig2, 10);     //Debounce

const char* char_params[] = {"Delay (ms)", "Duration (ms)", "IPI (ms)", "# of Pulses"};
int int_params[] = {' ', ' ', ' ', ' ', ' '}; //Allow for 4 entries pertaining to the char params strings.

//Define stim params
String temp_input; //Bad for ucontrollers bc fragments memory
char tot_str;
char stored[8] = "Stored ";    
char whichKey;
int numpos = 0;
int itNo = 0;

void setup() {
  lcd.begin(16, 2);
  Serial.begin(9600);
  pinMode(TTL1, OUTPUT);
  pinMode(LED1, OUTPUT);
  pinMode(trig1, INPUT_PULLUP);      //use pull-up resistor to set default to high
  pinMode(trig2, INPUT_PULLUP);      //use pull-up resistor to set default to high
  keypad.setDebounceTime(50);        //Debounce keypad
  splash();                          //Splash (welcome) screen
  delay(250);
  user_params();                     //Parameter setup
  delay(5);
}

void loop() {
  stim_gen();
}

void splash() {
  //Print splash screen to LCD
  lcd.setCursor(0, 0);
  lcd.print("Pulse Generator");
  lcd.setCursor(0, 1);
  lcd.print("     2017");
  delay (1500);
  lcd.clear();
}

void user_params() {
  while (itNo < 4) {
    lcd.setCursor(0, 0);
    lcd.print(char_params[itNo]);
    char whichKey = keypad.waitForKey();    //Previously char whichKey = keypad.getKey();
    if (whichKey == 'B' || whichKey == 'D' ) {   //define invalid keys
      numpos = 0;
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("  Invalid Key!");
      delay(1000);
      lcd.clear();
    }
    if (isDigit(whichKey)) {
      temp_input += whichKey;
      lcd.setCursor(0, 1);
      lcd.print("                                ");
      lcd.setCursor(0, 1);
      lcd.print(temp_input);
      numpos ++;
    }
    if (whichKey == '#') {          // # = Enter
      int_params[itNo] = temp_input.toInt();
      lcd.clear();
      lcd.setCursor(0, 1);
      lcd.print(stored + temp_input);
      delay(2500);           
      temp_input.remove(0);         //clear temp_input since it's been transferred to int_params;
      lcd.setCursor(0, 1);            //Clear line 2
      lcd.print("                                ");
      itNo++;
    }
    if (whichKey == '*') {   // * = Erase value
      lcd.clear();
      lcd.setCursor(0, 1);
      lcd.print("    Erased");
      temp_input.remove(0);
      delay(1000);
      lcd.setCursor(0, 1);            //Clear line 2
      lcd.print("                                ");
  }
  }
  

lcd.clear();
lcd.setCursor(0, 0);
lcd.print(" *** Active ***");
}

void stim_gen() {
  if (in_trig1.update() || in_trig2.update()) {              //look @ trig1 to see if changed state
    if (in_trig1.fallingEdge() || in_trig2.fallingEdge()) {        //and it was a falling edge
      for (int count = 0; count < int_params[3]; count++)  {  //Create new var count to act as place-holder/counter
        delay(int_params[0]);
        digitalWrite(TTL1, HIGH);
        digitalWrite(LED1, HIGH);
        delay(int_params[1]);
        digitalWrite(TTL1, LOW);
        digitalWrite(LED1, LOW);
        delay(int_params[2]);
      }
    }
  }
}

