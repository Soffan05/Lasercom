#ifndef VARIABLES_H
#define VARIABLES_h
#include <Arduino.h>

extern int sens_state;
extern int count;
extern const int NEXT_LETTER;
extern const int NEXT_WORD;
extern const int DOT_BLINK;
extern const int DASH_BLINK;
extern String ENCRYPT;
extern String translator;
extern String DECRYPT;
extern String RESULT;
extern bool encryptionDone;
extern int DOT_THRESHOLD;
extern String MORSE_CODE;
extern int SIGNAL_TIME;

#endif