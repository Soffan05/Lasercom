//Morse Code Rules:
//------------------------
//DOT = 1 Unit, DASH = 3 Units
//Space between letters = 3 Units
//Space between words = 7 Units


#define LED 8
#define sensor A0

#include <string.h>

//Variabler
String WORD = ""; //


//Variabler
int sens_state = 0; //Ljussensorns värde
int count = 0; //Hur länge ljuset lyser i singnalen (kolla input funktionen)
const int timing = 50; //En konstant timing för olika saker
int Next_sing = 200; // Timingen när nästa bokstav ska komma

String encrypt; //
String translator;
String decrypt;
String result;
String Morse_code = "";
int i = 0; //Räknar timingen mellan singnal

void dot() { //Funktion till att blinka en DOT (Kort blinkning)
  Serial.print(" .");
  digitalWrite(LED, LOW);
  delay(500);
  digitalWrite(LED, HIGH);
  delay(500);
}

void dash() { //Funktion till att blinka en DASH (Lång blinkning)
  Serial.print(" -");
  digitalWrite(LED, LOW);
  delay(500);
  digitalWrite(LED, LOW);
  delay(500);
}

String input(int sens_state) { //Funktion för att omvandla lasersingnal till kod
  String encrypt = "";
  while (true) {
    do {
      //FAS 1
      count++;
      sens_state = analogRead(sensor);
      delay(timing);
      //Serial.println(sens_state);
    } while (sens_state < 700);

    //FAS 2
    //Serial.println(count);
    switch (count) {
      case 3:
        encrypt += ".";
        count = 0;
        break;
      case 5:
        encrypt += "-";
        count = 0;
        break;
      default:
        Serial.println(encrypt);
        count = 0;
        break;
    }
    return encrypt; //RETURNING STRING
    break;
  }
}


String output(String encrypt) { //Funktion för att översätta morsekoden. Switch commandot funkade inte pga det gick inte att läga in sträningar i case. D: 
      if (encrypt == ".-") {
      translator = translator + "A";
      } else if (encrypt == "-...") {
        translator = translator + "B";
      } else if (encrypt == "-.-.") {
        translator = translator + "C";
      } else if (encrypt == "-..") {
        translator = translator + "D";
      } else if (encrypt == ".") {
        translator = translator + "E";
      } else if (encrypt == "..-.") {
        translator = translator + "F";
      } else if (encrypt == "--.") {
        translator = translator + "G";
      } else if (encrypt == "....") {
        translator = translator + "H";
      } else if (encrypt == "..") {
        translator = translator + "I";
      } else if (encrypt == ".---") {
        translator = translator + "J";
      } else if (encrypt == "-.-") {
        translator = translator + "K";
      } else if (encrypt == ".-..") {
        translator = translator + "L";
      } else if (encrypt == "--") {
        translator = translator + "M"; 
      } else if (encrypt == "-.") {
        translator = translator + "N";
      } else if(encrypt == "---") {
        translator = translator + "O";
      } else if (encrypt == ".--.") {
        translator = translator + "P";
      } else if (encrypt == "--.-") {
        translator = translator + "Q";
      } else if (encrypt == ".-.") {
        translator = translator + "R";
      } else if (encrypt == "...") {
        translator = translator + "S";
      } else if (encrypt == "-") {
        translator = translator + "T";
      } else if (encrypt == "..-") {
        translator = translator + "U";
      } else if (encrypt == "...-") {
        translator = translator + "V";
      } else if (encrypt == ".--") {
        translator = translator + "W";
      } else if (encrypt == "-..-") {
        translator = translator + "X";
      } else if (encrypt == "-.--") {
        translator = translator + "Y";
      } else if (encrypt == "--..") {
        translator = translator + "Z";
      }
  return translator;
}



void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  digitalWrite(LED, HIGH);

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


  sens_state = analogRead(sensor); //Ljussensorn kollar efter laserns ljus
  //Serial.println(sens_state);

  if (sens_state < 700) { //Här översätter programmet singnal till morsekod
    while (i < Next_sing) {
      i = 0;
      sens_state = analogRead(sensor); //Kollar om lasern fortfarande lyser loopen 
      encrypt = input(sens_state);
      Morse_code += encrypt; // "." eller "-" ska inkluderas i morsekoden
      Serial.println(Morse_code);
    
      while (sens_state > 700) { //Här räknar programmet ifall loopen ska stoppas eller fortsätta. Detta behövs för att programmet inte ska av mistag översätta morsekoden till en annan bokstav
        i++; 
        Serial.println(i);
        sens_state = analogRead(sensor);
        if (sens_state < 700) {
          break;
        } else if (i > Next_sing) {
          break;
        }
      }
    } 
    Serial.println("NEXT"); //Översättningen från singal till morsekod är klar
  }

  if (i > Next_sing) { //Här översätter programmet morsekoden till bokstäver och lägger in dem i en sträng variabel "result"
    decrypt = output(Morse_code); //Funktionen retunerar en bokstav i variabeln "decrypt"
    Morse_code = ""; //Morsekoden börjar om
    //Serial.println(decrypt);
    result += decrypt; //Den översättande bokstaven lägs in i resultatet
    Serial.println(result);
    Serial.println("DONE"); //Översättningen är klar
    
  }

  i = 0;


}

    

  





