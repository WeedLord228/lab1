M#include <Arduino.h>
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
Buzzer buzzer(PIN_BUZZER);

int notes[] = {NOTE_G3, NOTE_SILENCE, NOTE_G3, NOTE_SILENCE, NOTE_G3, NOTE_SILENCE, NOTE_DS3, NOTE_SILENCE};
double durations[] = {8, 8, 1, 8, 1, 8, 1, 24};
int melodyLength = 8;


void setup()
{
    buzzer.setMelody(notes, durations, melodyLength);
    buzzer.turnSoundOn();

    Serial.begin(115200);
    Serial.println("Started!");}

void loop() 
{
    buzzer.playSound();
    if (buttonOff.wasPressed())
    {
        buzzer.turnSoundOff();
    }
}
