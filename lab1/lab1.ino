#include <Arduino.h>
#include "pitches.h"
#include "button.h"
#include "buzzer.h"

#define PIN_BUZZER_1 2
#define PIN_BUZZER_2 3
#define PIN_BUZZER_3 4
#define PIN_BUZZER_4 5
#define PIN_BUTTON_OFF 6

Button buttonOff(PIN_BUTTON_OFF);
Buzzer buzzer(PIN_BUZZER_1);


int notes[] = {NOTE_G3, NOTE_B3};
double durations[] = {2, 2};
int pins[] = {2,3,4,5};
int melodyLength = 2;

void setup() {
  pinMode(PIN_BUZZER_1,OUTPUT);
  pinMode(PIN_BUZZER_2,OUTPUT);
  pinMode(PIN_BUZZER_3,OUTPUT);
  pinMode(PIN_BUZZER_4,OUTPUT);
    buzzer.setMelody(notes, durations, melodyLength,pins);
    buzzer.turnSoundOn();
}

void loop() {
  
    buzzer.playSound();
    if (buttonOff.wasPressed())
    {
        buzzer.turnSoundOff();
    }
}
