//Morse Code Rules:
//------------------------
//DOT = 1 Unit, DASH = 3 Units
//Space between letters = 3 Units
//Space between words = 7 Units


#define LASER 8
#define sensor 6

#include <LiquidCrystal_I2C.h>
#include "Functions.h"
#include "Variables.h"
#include <string.h>

#define QUESTION_B 2
#define YES_B 3
#define NO_B 4
#define CAL_B 5

int X = 16;
int Y = 2; 
LiquidCrystal_I2C lcd(0x27, X, Y);

int B_status = 1;
char questions[][25] = {"You like donuts?", "Cupcake?", "Ikea meatballs?", "Do you like dogs?","Are monkeys cool?", "Can you drive?"};
//char questions[][25] = {"Can penguins fly?", "Is earth flat?", "The muffin man?", "Is it disgusting?", "Crocodiles walk?", "Is math hard?"};
int i = 0;
int j = 0;
char sentence[25];
char *Letter = sentence;



void setup() {
  Serial.begin(9600);
  pinMode(LASER, OUTPUT);
  pinMode(sensor, INPUT);
  
  digitalWrite(LASER, HIGH);

  pinMode(QUESTION_B, INPUT); 
  pinMode(YES_B, INPUT);
  pinMode(NO_B, INPUT);
  pinMode(CAL_B, INPUT);

  lcd.init();
  lcd.backlight();
  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Waiting for");
  lcd.setCursor(0,1);
  lcd.print("signal ...");

}

void loop() {

  QB_status = digitalRead(QUESTION_B);
  YESB_status = digitalRead(YES_B);
  NOB_status = digitalRead(NO_B);
  CALB_status = digitalRead(CAL_B);  

  if (CALB_status && B_status) {
    while (true) {
      CALB_status = digitalRead(CAL_B); 
      digitalWrite(LASER, LOW);

      if (!CALB_status) {
        digitalWrite(LASER, HIGH);
        break;
      }     
    }
    MESSAGE = "";
    B_status = 0;
  } else if (NOB_status && B_status) {
    Letter = "NO";
    B_status = 0;
    MESSAGE = "";
  } else if (YESB_status && B_status) {
    Letter = "YES";
    B_status = 0;
    MESSAGE = "";
  } else if (QB_status && B_status) {
    Letter = questions[i];
    i++;
    if (i == 5) {
      i = 0;
    }
    B_status = 0;
    MESSAGE = "";
  }

  int str_len = strlen(Letter);


  if (!B_status) { //Denna kommer aktiveras när man skriver något i Serial Monitor
    while (j < str_len) {
      //Serial.println(Letter);

      int char_num = Letter[j];

      switch (char_num) { //Här kollar programmet vilken bokstav som är på plats inom "The serial buffer".
        case 65: //A
        case 97:
          Serial.println('A');
          dot();
          dash();
          delay(300);
          break;
        case 66: //B
        case 98:
          Serial.println('B');
          dash();
          dot();
          dot();
          dot();
          delay(300);
          break;
        case 67: //C
        case 99:
          Serial.println('C');
          dash();
          dot();
          dash();
          dot();
          delay(300);
          break;
        case 68: //D
        case 100:
          Serial.println('D');
          dash();
          dot();
          dot();
          delay(300);
          break;
        case 69: //E
        case 101:
          Serial.println('E');
          dot();
          delay(400);
          break;
        case 70: //F
        case 102:
          Serial.println('F');
          dot();
          dot();
          dash();
          dot();
          delay(300);
          break;
        case 71: //G
        case 103:
          Serial.println('G');
          dash();
          dash();
          dot();
          delay(300);
          break;
        case 72: //H
        case 104:
          Serial.println('H');
          dot();
          dot();
          dot();
          dot();
          delay(300);
          break;
        case 73: // I
        case 105:
          Serial.println('I');
          dot();
          dot();
          delay(300);
          break;
        case 74: //J
        case 106:
          Serial.println('J');
          dot();
          dash();
          dash();
          dash();
          delay(300);
          break;
        case 75: //K
        case 107:
          Serial.println('K');
          dash();
          dot();
          dash();
          delay(300);
          break;
        case 76: //L
        case 108:
          Serial.println('L');
          dot();
          dash();
          dot();
          dot();
          delay(300);
          break;
        case 77: //M
        case 109:
          Serial.println('M');
          dash();
          dash();
          delay(300);
          break;
        case 78: //N
        case 110:
          Serial.println('N');
          dash();
          dot();
          delay(300);
          break;
        case 79: //O
        case 111:
          Serial.println('O');
          dash();
          dash();
          dash();
          delay(300);
          break;
        case 80: //P
        case 112:
          Serial.println('P');
          dot();
          dash();
          dash();
          dot();
          delay(300);
          break;
        case 81: //Q
        case 113:
          Serial.println('Q');
          dash();
          dash();
          dot();
          dash();
          delay(300);
          break;
        case 82: //R
        case 114:
          Serial.println('R');
          dot();
          dash();
          dot();
          delay(300);
          break;
        case 83: //S
        case 115:
          Serial.println('S');
          dot();
          dot();
          dot();
          delay(300);
          break;
        case 84: //T
        case 116:
          Serial.println('T');
          dash();
          delay(300);
          break;
        case 85: //U
        case 117:
          Serial.println('U');
          dot();
          dot();
          dash();
          delay(300);
          break;
        case 86: //V
        case 118:
          Serial.println('V');
          dot();
          dot();
          dot();
          dash();
          delay(300);
          break;
        case 87: //W
        case 119:
          Serial.println('W');
          dot();
          dash();
          dash();
          delay(300);
          break;
        case 88: //X
        case 120:
          Serial.println('X');
          dash();
          dot();
          dot();
          dash();
          delay(300);
          break;
        case 89: //Y
        case 121:
          Serial.println('Y');
          dash();
          dot();
          dash();
          dash();
          delay(300);
          break;
        case 90: //Z
        case 122:
          Serial.println('Z');
          dash();
          dash();
          dot();
          dot();
          delay(300);
          break;
        case 63:
          dot();
          dot();
          dash();
          dash();
          dot();
          dot();
          delay(300);
        case 32:
          delay(500); //SPACE 
        default:
          break;  
      }

      j++;
    } 
    Letter = "";
    j = 0;
  }

  if (!CALB_status && !NOB_status && !YESB_status && !QB_status ) {
      B_status = 1;

  }


 //Programmet startar här
  
  sens_state = digitalRead(sensor); //Ljussensorn kollar efter laserns ljus

  if (!encryptionDone && sens_state == 0) {
    do {
      ENCRYPT = "";
      SIGNAL_TIME = 0;
      Serial.print("Encrypting Morse Code: ");
      ENCRYPT = input(sens_state);
      MORSE_CODE += ENCRYPT;
      sens_state = digitalRead(sensor);
      Serial.println(MORSE_CODE);

      while (sens_state == 1) { //ardinon räknar hur länge ljussensorn inte är utsätts för laserns ljus
        SIGNAL_TIME++;
        sens_state = digitalRead(sensor);
        Serial.print("Timing: ");
        Serial.println(SIGNAL_TIME);
        if (sens_state == 0) { //Nästa signal
          break;
        } else if (SIGNAL_TIME > NEXT_WORD) {
          break;
        }
      }

      if (SIGNAL_TIME >= NEXT_LETTER && SIGNAL_TIME < NEXT_WORD) {
        Serial.println("Nästa bokstav");
        break;
      }
    } while (SIGNAL_TIME < NEXT_LETTER || SIGNAL_TIME < NEXT_WORD);
       
      encryptionDone = true;
  }
  

  if (encryptionDone) {
    DECRYPT = output(MORSE_CODE);
    MESSAGE += DECRYPT;
    MORSE_CODE = "";
    Serial.println(MESSAGE);
    if (SIGNAL_TIME >= NEXT_WORD) {
      MESSAGE += " ";
    }
    SIGNAL_TIME = 0;
    ENCRYPT = "";

    
    lcd.clear();
    lcd.print(MESSAGE);

    encryptionDone = false;
    Serial.println("Next signal");
  }
}
