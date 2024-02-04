//Morse Code Rules:
//------------------------
//DOT = 1 Unit, DASH = 3 Units
//Space between letters = 3 Units
//Space between words = 7 Units



#define LED 8
#define sensor A0

#include <string.h>

//Variabler
String WORD = "";
int timing = 200;
int i = 10;

//Variabler för ljussensorn
int sens_state = 0;
int count = 0;
int garante = 0;

//Variabler för översättning
String encrypt;
String translator;

void dot() {
  Serial.print(" .");
  digitalWrite(LED, LOW);
  delay(500);
  digitalWrite(LED, HIGH);
  delay(500);
}

void dash() {
  Serial.print(" -");
  digitalWrite(LED, LOW);
  delay(500);
  digitalWrite(LED, LOW);
  delay(500);
}

void translation(String encrypt) {
      if (encrypt == ".-") {
      translator = translator + "A";
    }
    if (encrypt == "-...") {
      translator = translator + "B";
    }
    if (encrypt == "-.-.") {
      translator = translator + "C";
    }
    if (encrypt == "-..") {
      translator = translator + "D";
    }
    if (encrypt == ".") {
      translator = translator + "E";
    }
    if (encrypt == "..-.") {
      translator = translator + "F";
    }
    if (encrypt == "--.") {
      translator = translator + "G";
    }
    if (encrypt == "....") {
      translator = translator + "H";
    }
    if (encrypt == "..") {
      translator = translator + "I";
    }
    if (encrypt == ".---") {
      translator = translator + "J";
    }
    if (encrypt == "-.-") {
      translator = translator + "K";
    }
    if (encrypt == ".-..") {
      translator = translator + "L";
    }
    if (encrypt == "--") {
      translator = translator + "M"; 
    }
    if (encrypt == "-.") {
      translator = translator + "N";
    }
    if (encrypt == "---") {
      translator = translator + "O";
    }
    if (encrypt == ".--.") {
      translator = translator + "P";
    }
    if (encrypt == "--.-") {
      translator = translator + "Q";
    }
    if (encrypt == ".-.") {
      translator = translator + "R";
    }
    if (encrypt == "...") {
      translator = translator + "S";
    }
    if (encrypt == "-") {
      translator = translator + "T";
    }
    if (encrypt == "..-") {
      translator = translator + "U";
    }
    if (encrypt == "...-") {
      translator = translator + "v";
    }
    if (encrypt == ".--") {
      translator = translator + "w";
    }
    if (encrypt == "-..-") {
      translator = translator + "X";
    }
    if (encrypt == "-.--") {
      translator = translator + "Y";
    }
    if (encrypt == "--..") {
      translator = translator + "Z";
    }
    encrypt = "";
    Serial.println(translator);

}


void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  digitalWrite(LED, HIGH);

}



void loop() {

  if (Serial.available() > 0) {
    while (true) {
    
    
    char Letter = Serial.read();

    WORD += Letter;    
    Serial.print(Letter);

 
    switch (Letter) {
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
        Serial.println("Non lettern\n");
        Serial.print(WORD);
        break;
    
    }
    Serial.println("\n");
    break;
    } 
    WORD = "";
  }
      //FAS 1
sens_state = analogRead(sensor);

  if (sens_state < 700) {
    while (true) {
      while (sens_state < 700) {
      count = count + 1;
      Serial.println(count);
      garante = count;
      delay(timing);
      sens_state = analogRead(sensor);
      //FAS 2
      if (sens_state > 700) {
        if (garante == 2) {
          encrypt = encrypt + ".";
        } else if (garante == 4) {
          encrypt = encrypt + "-";
        }
      Serial.println(encrypt);
      break;
        }
      translation(encrypt);
      }
    }
    i = 0;
    encrypt = "";
  }
  
  count = 0;
  garante = 0;




}

