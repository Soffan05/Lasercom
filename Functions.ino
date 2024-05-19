#include "Variables.h"
#define LASER 8

void dot() { //Funktion till att blinka en DOT (Kort blinkning)
  Serial.print(" .");
  digitalWrite(LASER, LOW);
  delay(DOT_BLINK);
  digitalWrite(LASER, HIGH);
  delay(200); //Ändra till NEXT_LETTER???
}

void dash() { //Funktion till att blinka en DASH (Lång blinkning)
  Serial.print(" -");
  digitalWrite(LASER, LOW);
  delay(DASH_BLINK);
  digitalWrite(LASER, HIGH);
  delay(200); //Ändra till NEXT_LETTER???
}

String input(int sens_state) { //Funktion för att omvandla lasersingnal till kod
  count = 0;
  while (true) {
    do  {
      //FAS 1
      count++;
      sens_state = digitalRead(sensor);
      delay(50);
      Serial.println("Count:");
      Serial.println(count);
    } while (sens_state == 0);

    //FAS 2
    //Serial.println(count);

    if (count < DOT_THRESHOLD) {
        ENCRYPT = ".";
        break;
    } else if (count > DOT_THRESHOLD) {
        ENCRYPT = "-";
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
      } else if (ENCRYPT == "..--..") {
        translator = "?";
      }
  return translator;
}

