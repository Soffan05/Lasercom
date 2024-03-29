//Morse Code Rules:
//------------------------
//DOT = 1 Unit, DASH = 3 Units
//Space between letters = 3 Units
//Space between words = 7 Units


#define LASER 8
#define sensor A0

#include <LiquidCrystal_I2C.h>
#include <string.h>

int X = 16;
int Y = 2; 
LiquidCrystal_I2C lcd(0x27, X, Y);

//Variabler
int sens_state = 0; //Ljussensorns värde
int count = 0; //Hur länge ljuset lyser i singnalen (kolla input funktionen)
const int timing = 50; //En konstant timing för olika saker
const int NEXT_LETTER = 200; // Timingen när nästa bokstav ska komma
const int NEXT_WORD = 250; //Denna ska alltid vara större än NEXT_LETTER
const int BLINK = 200;
String ENCRYPT; //
String translator;
String DECRYPT;
String RESULT;
bool encryptionDone = false;
DOT_THRESHOLD = 10;
String MORSE_CODE = "";
int SIGNAL_TIME = 0; //Räknar timingen mellan singnal

void dot() { //Funktion till att blinka en DOT (Kort blinkning)
  Serial.print(" .");
  digitalWrite(LASER, LOW);
  delay(BLINK);
  digitalWrite(LASER, HIGH);
  delay(800); //Ändra till NEXT_LETTER???
}

void dash() { //Funktion till att blinka en DASH (Lång blinkning)
  Serial.print(" -");
  digitalWrite(LASER, LOW);
  delay(BLINK * 3);
  digitalWrite(LASER, LOW);
  delay(800); //Ändra till NEXT_LETTER???
}

String input(int sens_state) { //Funktion för att omvandla lasersingnal till kod
  String ENCRYPT = "";
  count = 0;
  while (true) {
    do  {
      //FAS 1
      count++;
      sens_state = digitalRead(sensor);
      delay(timing);
      //Serial.println(sens_state);
    } while (sens_state == 0);

    //FAS 2
    Serial.println(count);

    if (count <= DOT_THRESHOLD) {
        ENCRYPT += ".";
        break;
    } else if (count > DOT_THRESHOLD) {
        ENCRYPT += "-";
        break;
    }

  }
  count = 0;
  return ENCRYPT; //RETURNING STRING

}


String output(String ENCRYPT) { //Funktion för att översätta morsekoden. Switch commandot funkade inte pga det gick inte att läga in sträningar i case. D: 
      if (ENCRYPT == ".-") {
      translator = "A";
      } else if (ENCRYPT == "-...") {
        translator = "B";
      } else if (ENCRYPT == "-.-.") {
        translator = "C";
      } else if (ENCRYPT == "-..") {
        translator = "D";
      } else if (ENCRYPT == ".") {
        translator = "E";
      } else if (ENCRYPT == "..-.") {
        translator = "F";
      } else if (ENCRYPT == "--.") {
        translator = "G";
      } else if (ENCRYPT == "....") {
        translator = "H";
      } else if (ENCRYPT == "..") {
        translator = "I";
      } else if (ENCRYPT == ".---") {
        translator = "J";
      } else if (ENCRYPT == "-.-") {
        translator = "K";
      } else if (ENCRYPT == ".-..") {
        translator = "L";
      } else if (ENCRYPT == "--") {
        translator = "M"; 
      } else if (ENCRYPT == "-.") {
        translator = "N";
      } else if(ENCRYPT == "---") {
        translator = "O";
      } else if (ENCRYPT == ".--.") {
        translator = "P";
      } else if (ENCRYPT == "--.-") {
        translator = "Q";
      } else if (ENCRYPT == ".-.") {
        translator = "R";
      } else if (ENCRYPT == "...") {
        translator = "S";
      } else if (ENCRYPT == "-") {
        translator = "T";
      } else if (ENCRYPT == "..-") {
        translator = "U";
      } else if (ENCRYPT == "...-") {
        translator = "V";
      } else if (ENCRYPT == ".--") {
        translator = "W";
      } else if (ENCRYPT == "-..-") {
        translator = "X";
      } else if (ENCRYPT == "-.--") {
        translator = "Y";
      } else if (ENCRYPT == "--..") {
        translator = "Z";
      } 
  return translator;
}



void setup() {
  Serial.begin(9600);
  pinMode(LASER, OUTPUT);
  
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
    Serial.print(Letter);

 
    switch (Letter) { //Här kollar programmet vilken bokstav som är på plats inom "The serial buffer".
      case 65: //A
      case 97:
        dot();
        dash();
        break;
      case 66: //B
      case 98:
        dash();
        dot();
        dot();
        dot();
        break;
      case 67: //C
      case 99:
        dash();
        dot();
        dash();
        dot();
        break;
      case 68: //D
      case 100:
        dash();
        dot();
        dot();
        break;
      case 69: //E
      case 101:
        dot();
        break;
      case 70: //F
      case 102:
        dot();
        dot();
        dash();
        dot();
        break;
      case 71: //G
      case 103:
        dash();
        dash();
        dot();
        break;
      case 72: //H
      case 104:
        dot();
        dot();
        dot();
        dot();
        break;
      case 73: //
      case 105:
        dot();
        dot();
        break;
      case 74: //J
      case 106:
        dot();
        dash();
        dash();
        dash();
        break;
      case 75: //K
      case 107:
        dash();
        dot();
        dash();
        break;
      case 76: //L
      case 108:
        dot();
        dash();
        dot();
        dot();
        break;
      case 77: //M
      case 109:
        dash();
        dash();
        break;
      case 78: //N
      case 110:
        dash();
        dot();
        break;
      case 79: //O
      case 111:
        dash();
        dash();
        dash();
        break;
      case 80: //P
      case 112:
        dot();
        dash();
        dash();
        dot();
        break;
      case 81: //Q
      case 113:
        dash();
        dash();
        dot();
        dash();
        break;
      case 82: //R
      case 114:
        dot();
        dash();
        dot();
        break;
      case 83: //S
      case 115:
        dot();
        dot();
        dot();
        break;
      case 84: //T
      case 116:
        dash();
        break;
      case 85: //U
      case 117:
        dot();
        dot();
        dash();
        break;
      case 86: //V
      case 118:
        dot();
        dot();
        dot();
        dash();
        break;
      case 87: //W
      case 119:
        dot();
        dash();
        dash();
        break;
      case 88: //X
      case 120:
        dash();
        dot();
        dot();
        dash();
        break;
      case 89: //Y
      case 121:
        dash();
        dot();
        dash();
        dash();
        break;
      case 90: //Z
      case 122:
        dash();
        dash();
        dot();
        dot();
        break;
      case 32:
        delay(1000); //SPACE 
      default:
        Serial.println("Non lettern\n"); //Ingen bokstav
        break;
    
    }
    Serial.println("\n");
    break;
    } 
  }


  sens_state = digitalRead(sensor); //Ljussensorn kollar efter laserns ljus
  //Serial.println("Start");
  if (!encryptionDone && sens_state == 0) {
    while (SIGNAL_TIME < NEXT_LETTER) {
      Serial.print("Encrypting Morse Code: ");
      ENCRYPT = input(sens_state);
      MORSE_CODE += ENCRYPT;
      sens_state = digitalRead(sensor);
      Serial.println(MORSE_CODE);

      while (sens_state == 1) {
        sens_state = digitalRead(sensor);
        SIGNAL_TIME++;
        Serial.println(i);

        if (sens_state == 0) { //Nästa signal
          break;
        }
          
        if (SIGNAL_TIME > NEXT_LETTER) { //Nästa bokstav
          SIGNAL_TIME = 0;
        }
        if (SIGNAL_TIME > NEXT_WORD) { //Nästa ord
          SIGNAL_TIME = 0;
          RESULT += " ";
        }

    encryptionDone = true;
  }

  if (encryptionDone) {
    DECRYPT = output(MORSE_CODE);
    RESULT += DECRYPT;
    MORSE_CODE = "";
    //Serial.println(RESULT);
    i = 0;
    
    lcd.clear();
    lcd.print(RESULT);
    encryptionDone = false;
    Serial.println("Next signal");
  }
}



    

  





