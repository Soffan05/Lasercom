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
int NEXT_SIGNAL = 200; // Timingen när nästa bokstav ska komma
const int BLINK = 200;
String ENCRYPT; //
String translator;
String DECRYPT;
String result;
bool encryptionDone = false;
DOT_THRESHOLD = 10;
String Morse_code = "";
int SIGNAL_TIME = 0; //Räknar timingen mellan singnal

void dot() { //Funktion till att blinka en DOT (Kort blinkning)
  Serial.print(" .");
  digitalWrite(LASER, LOW);
  delay(BLINK);
  digitalWrite(LASER, HIGH);
  delay(800); //Ändra till NEXT_SIGNAL???
}

void dash() { //Funktion till att blinka en DASH (Lång blinkning)
  Serial.print(" -");
  digitalWrite(LASER, LOW);
  delay(BLINK * 3);
  digitalWrite(LASER, LOW);
  delay(800); //Ändra till NEXT_SIGNAL???
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
    
    
    char Letter = Serial.read(); 
    Serial.print(Letter);

 
    switch (Letter) { //Här kollar programmet vilken bokstav som är på plats inom "The serial buffer".
      case 'a':
      case 'A':
        dot();
        dash();
        break;
      case 'b':
      case 'B':
        dash();
        dot();
        dot();
        dot();
        break;
      case 'c':
      case 'C':
        dash();
        dot();
        dash();
        dot();
        break;
      case 'd':
      case 'D':
        dash();
        dot();
        dot();
        break;
      case 'e':
      case 'E':
        dot();
        break;
      case 'f':
      case 'F':
        dot();
        dot();
        dash();
        dot();
        break;
      case 'g':
      case 'G':
        dash();
        dash();
        dot();
        break;
      case 'h':
      case 'H':
        dot();
        dot();
        dot();
        dot();
        break;
      case 'i':
      case 'I':
        dot();
        dot();
        break;
      case 'j':
      case 'J':
        dot();
        dash();
        dash();
        dash();
        break;
      case 'k':
      case 'K':
        dash();
        dot();
        dash();
        break;
      case 'l':
      case 'L':
        dot();
        dash();
        dot();
        dot();
        break;
      case 'm':
      case 'M':
        dash();
        dash();
        break;
      case 'n':
      case 'N':
        dash();
        dot();
        break;
      case 'o':
      case 'O':
        dash();
        dash();
        dash();
        break;
      case 'p':
      case 'P':
        dot();
        dash();
        dash();
        dot();
        break;
      case 'q':
      case 'Q':
        dash();
        dash();
        dot();
        dash();
        break;
      case 'r':
      case 'R':
        dot();
        dash();
        dot();
        break;
      case 's':
      case 'S':
        dot();
        dot();
        dot();
        break;
      case 't':
      case 'T':
        dash();
        break;
      case 'u':
      case 'U':
        dot();
        dot();
        dash();
        break;
      case 'v':
      case 'V':
        dot();
        dot();
        dot();
        dash();
        break;
      case 'w':
      case 'W':
        dot();
        dash();
        dash();
        break;
      case 'x':
      case 'X':
        dash();
        dot();
        dot();
        dash();
        break;
      case 'y':
      case 'Y':
        dash();
        dot();
        dash();
        dash();
        break;
      case 'z':
      case 'Z':
        dash();
        dash();
        dot();
        dot();
        break;
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
    while (SIGNAL_TIME < NEXT_SIGNAL) {
      Serial.print("Encrypting Morse Code: ");
      ENCRYPT = input(sens_state);
      Morse_code += ENCRYPT;
      sens_state = digitalRead(sensor);
      Serial.println(Morse_code);

      while (sens_state == 1) {
        sens_state = digitalRead(sensor);
        SIGNAL_TIME++;
        Serial.println(i);

        if (sens_state == 0) { //Nästa signal
          SIGNAL_TIME = 0;
          break;
        } else if (i > NEXT_SIGNAL) { //Gå vidare till översättning
          break;
        }
      }

    }

    encryptionDone = true;
  }

  if (encryptionDone) {
    DECRYPT = output(Morse_code);
    result += DECRYPT;
    Morse_code = "";
    //Serial.println(result);
    i = 0;
    
    lcd.clear();
    lcd.print(result);
    encryptionDone = false;
    Serial.println("Next signal");
  }
}



    

  





