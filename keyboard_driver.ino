// #include <math.h>

#define RED 10
#define GREEN 11
#define BLUE 12
#define HID_PINS 2

const unsigned int HID[HID_PINS] = {3,5};

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.

  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);

  // HID pins
  for(int i = 0; i<HID_PINS;i++){
    pinMode(HID[i], INPUT);
  }
}

int pow(int num, int exp){
    if(exp == 0){
        return 1;
    }
    int tot = 1;
    for (int i = 0; i<exp; i++){
        tot *= num;
    }
    return tot;
}


int key(){
  int val = 0;
  for(int i = 0; i<HID_PINS;i++){
    if(digitalRead(HID[i])){
      val += pow(2, i);
    }
  }
  return val;
}

// the loop function runs over and over again forever
void loop() {
  switch(key()){
    case 1:
      digitalWrite(RED, HIGH);
      digitalWrite(GREEN, LOW);
      digitalWrite(BLUE, LOW);
      break;
    case 2:
      digitalWrite(RED, LOW);
      digitalWrite(GREEN, HIGH);
      digitalWrite(BLUE, LOW);
      break;
    case 3:
      digitalWrite(RED, LOW);
      digitalWrite(GREEN, LOW);
      digitalWrite(BLUE, HIGH);
      break;
    default:
      digitalWrite(RED, LOW);
      digitalWrite(GREEN, LOW);
      digitalWrite(BLUE, LOW);
  }
  delay(200);
}
