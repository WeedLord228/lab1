#pragma once

#define BUZZER_NOTE_DURATION 100

class Buzzer
{
public:
    Buzzer(int _pin)
    {
        pin = _pin;

        isEnabled = false;
        currentNote = 0;
        currentPin = 0;
        noteStartedMs = 0;

        pins = 0;
        notes = 0;
        durations = 0;
        melodyLength = 0;
    }

    void setPin(int _pin)
    {
        pin = _pin;
    }


    void turnSoundOn()
    {
        isEnabled = true;
        currentNote = 0;
        noteStartedMs = 0;
    }

    void turnSoundOff()
    {
        isEnabled = false;
        currentNote = 0;
        noteStartedMs = 0;
        noTone(pin);
    }

    void setMelody(int _notes[], double _durations[], int _melodyLength,int _pins[])
    {
      pins = _pins;   
        notes = _notes;
        durations = _durations;
        melodyLength = _melodyLength;
    }
    void playSound()
    {
        if (!isEnabled)
            return;

        unsigned long duration = round(BUZZER_NOTE_DURATION*durations[currentNote]);
        if ((millis() - noteStartedMs) > duration)
        {
            int note = notes[currentNote];
             
            
            if (note == NOTE_SILENCE){
                noTone(pin);
                currentPin = (currentPin+1)%4;
                pin = pins[currentPin];
            }
            else 
                tone(pin, notes[currentNote]);

            noteStartedMs = millis();
            currentNote = (currentNote + 1)%melodyLength;
//            currentPin = (currentPin+1)%4;
        }
    }

private:
    int pin;
    bool isEnabled;

    int currentPin;
    int currentNote;
    unsigned long noteStartedMs;

    int* pins;
    int* notes;
    double* durations;
    int melodyLength;
};
