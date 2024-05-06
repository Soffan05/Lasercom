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

int X = 16;
int Y = 2; 
LiquidCrystal_I2C lcd(0x27, X, Y);

void setup() {
  Serial.begin(9600);
  pinMode(LASER, OUTPUT);
  pinMode(sensor, INPUT);
  
  digitalWrite(LASER, HIGH);

  lcd.init();
  lcd.backlight();
  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Waiting for");
  lcd.setCursor(0,1);
  lcd.print("signal ...");

}

void loop() {

  if (Serial.available() > 0) { //Denna kommer aktiveras när man skriver något i Serial Monitor
    while (true) {
     
    int Letter = Serial.read();
    char letter = Letter; 
    Serial.print(letter);

 
    switch (Letter) { //Här kollar programmet vilken bokstav som är på plats inom "The serial buffer".
      case 65: //A
      case 97:
        dot();
        dash();
        delay(300);
        break;
      case 66: //B
      case 98:
        dash();
        dot();
        dot();
        dot();
        delay(300);
        break;
      case 67: //C
      case 99:
        dash();
        dot();
        dash();
        dot();
        delay(300);
        break;
      case 68: //D
      case 100:
        dash();
        dot();
        dot();
        delay(300);
        break;
      case 69: //E
      case 101:
        dot();
        delay(300);
        break;
      case 70: //F
      case 102:
        dot();
        dot();
        dash();
        dot();
        delay(300);
        break;
      case 71: //G
      case 103:
        dash();
        dash();
        dot();
        delay(300);
        break;
      case 72: //H
      case 104:
        dot();
        dot();
        dot();
        dot();
        delay(300);
        break;
      case 73: // I
      case 105:
        dot();
        dot();
        delay(300);
        break;
      case 74: //J
      case 106:
        dot();
        dash();
        dash();
        dash();
        delay(300);
        break;
      case 75: //K
      case 107:
        dash();
        dot();
        dash();
        delay(300);
        break;
      case 76: //L
      case 108:
        dot();
        dash();
        dot();
        dot();
        delay(300);
        break;
      case 77: //M
      case 109:
        dash();
        dash();
        delay(300);
        break;
      case 78: //N
      case 110:
        dash();
        dot();
        delay(300);
        break;
      case 79: //O
      case 111:
        dash();
        dash();
        dash();
        delay(300);
        break;
      case 80: //P
      case 112:
        dot();
        dash();
        dash();
        dot();
        delay(300);
        break;
      case 81: //Q
      case 113:
        dash();
        dash();
        dot();
        dash();
        delay(300);
        break;
      case 82: //R
      case 114:
        dot();
        dash();
        dot();
        delay(300);
        break;
      case 83: //S
      case 115:
        dot();
        dot();
        dot();
        delay(300);
        break;
      case 84: //T
      case 116:
        dash();
        delay(300);
        break;
      case 85: //U
      case 117:
        dot();
        dot();
        dash();
        delay(300);
        break;
      case 86: //V
      case 118:
        dot();
        dot();
        dot();
        dash();
        delay(300);
        break;
      case 87: //W
      case 119:
        dot();
        dash();
        dash();
        delay(300);
        break;
      case 88: //X
      case 120:
        dash();
        dot();
        dot();
        dash();
        delay(300);
        break;
      case 89: //Y
      case 121:
        dash();
        dot();
        dash();
        dash();
        delay(300);
        break;
      case 90: //Z
      case 122:
        dash();
        dash();
        dot();
        dot();
        delay(300);
        break;
      case 32:
        delay(500); //SPACE 
      default:
        break;  
    }
    Serial.println("\n");
    break;
    } 
  }


  sens_state = digitalRead(sensor); //Ljussensorn kollar efter laserns ljus
  //Serial.println(sens_state);

  if (!encryptionDone && sens_state == 0) {
    do {
      ENCRYPT = "";
      SIGNAL_TIME = 0;
      Serial.print("Encrypting Morse Code: ");
      ENCRYPT = input(sens_state);
      MORSE_CODE += ENCRYPT;
      sens_state = digitalRead(sensor);
      Serial.println(MORSE_CODE);

      while (sens_state == 1) {
        sens_state = digitalRead(sensor);
        SIGNAL_TIME++;
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
    RESULT += DECRYPT;
    MORSE_CODE = "";
    //Serial.println(RESULT);
    if (SIGNAL_TIME >= NEXT_WORD) {
      RESULT += " ";
    }
    SIGNAL_TIME = 0;
    ENCRYPT = "";

    
    lcd.clear();
    lcd.print(RESULT);

    encryptionDone = false;
    Serial.println("Next signal");
  }
}