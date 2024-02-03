//Morse Code Rules:
//------------------------
//DOT = 1 Unit, DASH = 3 Units
//Space between letters = 3 Units
//Space between words = 7 Units

#define LED 8
#define sensor A0

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
  digitalWrite(LED, HIGH);
  delay(500);
}


void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  digitalWrite(LED, HIGH);

}

//Variabler
  String WORD = "";
  int i = 0;
  int WORD_len = 0;

//Variabler för ljussensorn
int sens_state = 0;
int count = 0;
int garante = 0;

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
      
        

    }


    if ((Letter == 'a') || (Letter == 'A')){
      dot();
      dash();
    }
    if ((Letter == 'b') || (Letter == 'B')){
      dash();
      dot();
      dot();
      dot();
    }
    if ((Letter == 'c') || (Letter == 'C')){
      dash();
      dot();
      dash();
      dot();

    }
    if ((Letter == 'd') || (Letter == 'D')){
      dash();
      dot();
      dot();

    }
    if ((Letter == 'e') || (Letter == 'E')){
      dot();

    }
    if ((Letter == 'f') || (Letter == 'F')){
      dot();
      dot();
      dash();
      dot();

    }
    if ((Letter == 'g') || (Letter == 'G')){
      dash();
      dash();
      dot();

    }
    if ((Letter == 'h') || (Letter == 'H')){
      dot();
      dot();
      dot();
      dot();

    }
    if ((Letter == 'i') || (Letter == 'I'))  {
      dot();
      dot();

    }
    if ((Letter == 'j') || (Letter == 'J')){
      dot();
      dash();
      dash();
      dash();

    }
    if ((Letter == 'k') || (Letter == 'K')){
      dash();
      dot();
      dash();
    }
    if ((Letter == 'l') || (Letter == 'L')){
      dot();
      dash();
      dot();
      dot();

    }
    if ((Letter == 'm') || (Letter == 'M')){
      dash();
      dash();

    }
    if ((Letter == 'n') || (Letter == 'N')){
      dash();
      dot();

    }
    if ((Letter == 'o') || (Letter == 'O')){
      dash();
      dash();
      dash();

    }
    if ((Letter == 'p') || (Letter == 'P')){
      dot();
      dash();
      dash();
      dot();

    }
    if ((Letter == 'q') || (Letter == 'Q')){
      dash();
      dash();
      dot();
      dash();

    }
    if ((Letter == 'r') || (Letter == 'R')){
      dot();
      dash();
      dot();

    }
    if ((Letter == 's') || (Letter == 'S')){
      dot();
      dot();
      dot();

    }
    if ((Letter == 't') || (Letter == 'T')){
      dash();

    }
    if ((Letter == 'u') || (Letter == 'U')){
      dot();
      dot();
      dash();

    }
    if ((Letter == 'v') || (Letter == 'V')){
      dot();
      dot();
      dot();
      dash();

    }
    if ((Letter == 'w') || (Letter == 'W')){ 
      dot();
      dash();
      dash();

    }
    if ((Letter == 'x') || (Letter == 'X')){
      dash();
      dot();
      dot();
      dash();

    }
    if ((Letter == 'y') || (Letter == 'Y')){
      dash();
      dot();
      dash();
      dash();

    }
    if ((Letter == 'z') || (Letter == 'Z')){
      dash();
      dash();
      dot();
      dot();

    }
    if (Letter == ' ') {
      Serial.print("SPACE");
      delay(1750);

      
    }
    i += 1;
    Serial.println("\n");
    break;
    }
  }
    //FAS 1
  sens_state = analogRead(sensor);

  while (sens_state < 700) {
    count = count + 1;
    Serial.println(count);
    garante = count;
    delay(1000);
    sens_state = analogRead(sensor);
    //FAS 2
    if (sens_state > 700) {
      if (garante == 3) {
        Serial.println(".");
        Serial.println("Next");
      } else if (garante == 9) {
        Serial.println("-");
        Serial.println("Next");
      }


    break;
    }
  }
  count = 0;

  garante = 0;
}
