#include "musicman.h"

Buzzer::Buzzer(int p, BuzzerType bt)
{
    pin = p;
    buzzerType = bt;

    pinMode(pin, OUTPUT);
}

void Buzzer::setPin(int p)
{
    pin = p;
}

void Buzzer::setBuzzerType(BuzzerType bt)
{
    buzzerType = bt;
}

void Buzzer::play(Notes note, NoteType noteType, bool isDotted)
{
    const long dur = getDuration(noteType, isDotted);

    if (buzzerType == ACTIVE)
    {
        if (dur == -1)
        {
            tone(pin, note);
        }
        else
        {
            tone(pin, note, dur);
        }
    }
    else if (buzzerType == PASSIVE)
    {
        constexpr unsigned long halfPeriodMicros = 1000000 / (Notes::C4 *2);	// Assuming C4 as reference note

        if (dur == -1)
        {
            while (true)
            {
                digitalWrite(pin, HIGH);
                delayMicroseconds(halfPeriodMicros);
                digitalWrite(pin, LOW);
                delayMicroseconds(halfPeriodMicros);
            }
        }
        else
        {
            const unsigned long endTime = millis() + dur;
            while (millis() < endTime)
            {
                digitalWrite(pin, HIGH);
                delayMicroseconds(halfPeriodMicros);
                digitalWrite(pin, LOW);
                delayMicroseconds(halfPeriodMicros);
            }
        }
    }
}

void Buzzer::off()
{
    if (buzzerType == ACTIVE)
    {
        noTone(pin);
    }
    else if (buzzerType == PASSIVE)
    {
        digitalWrite(pin, LOW);
    }
}

double getNoteDuration(NoteType noteType, bool isDotted = false)
{
    const double beatsPerMinute = static_cast<double> (tempo);
    const double quarterNoteDuration = 60.0 / beatsPerMinute;
    double duration = 0.0;

    switch (noteType)
    {
        case WHOLE:
            duration = quarterNoteDuration * 4;
            break;
        case HALF:
            duration = quarterNoteDuration * 2;
            break;
        case QUARTER:
            duration = quarterNoteDuration;
            break;
        case EIGHTH:
            duration = quarterNoteDuration / 2;
            break;
        case SIXTEENTH:
            duration = quarterNoteDuration / 4;
            break;
        default:
            std::cerr << "Invalid note type\n";
            break;
    }

    if (isDotted)
    {
       	// Increase the duration for dotted notes
        duration += duration / 2.0;
    }

    return duration;
}
