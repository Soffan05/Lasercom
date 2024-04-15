//Variabler
int sens_state = 1; //Ljussensorns värde
int count = 0; //Hur länge ljuset lyser i singnalen (kolla input funktionen)
const int NEXT_LETTER = 20; // Timingen när nästa bokstav ska komma
const int NEXT_WORD = 65; //Denna ska alltid vara större än NEXT_LETTER
const int DOT_BLINK = 100;
const int DASH_BLINK = DOT_BLINK * 3;
String ENCRYPT; //
String translator;
String DECRYPT;
String RESULT;
bool encryptionDone = false;
int DOT_THRESHOLD = 5;
String MORSE_CODE = "";
int SIGNAL_TIME = 0; //Räknar timingen mellan singnal