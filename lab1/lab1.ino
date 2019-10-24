#include <Arduino.h>
#include <MD_TCS230.h>
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

int notes[] = {NOTE_G3, SILENCE_NOTE};
double durations[] = {2,2};
int melodyLength = 2;
bool roundIsPlaying = false;

void setup()
{
    buzzer.setMelody(notes, durations, melodyLength);
    buzzer.turnSoundOn();

    Serial.begin(115200);
    Serial.println("Started!");
}

void loop() 
{
    if(!roundIsPLaying)  
    {
      buzzer.playRound();
    }
    if (buttonOff.wasPressed())
    {
        buzzer.turnSoundOff();
    }
}

void playRound()
{
    roundIsPlaying = true;
    buzzer.setPin(PIN_BUZZER_1);
    buzzer.playSound();
    buzzer.setPin(PIN_BUZZER_2);
    buzzer.playSound();
    buzzer.setPin(PIN_BUZZER_3);
    buzzer.playSound();
    buzzer.setPin(PIN_BUZZER_4);
    buzzer.playSound();
    roundIsPlaying = false;
}
