// musicman.h file

#ifndef musicman_h
#define musicman_h 

#include "Arduino.h"

enum BuzzerType : uint8_t {
	ACTIVE,
	PASSIVE
};

enum Notes : uint8_t {
    C0  = 16,
    CS0 = 17,
    Db0 = 17,
    D0  = 18,
    DS0 = 19,
    Eb0 = 19,
    E0  = 21,
    F0  = 22,
    FS0 = 23,
    Gb0 = 23,
    G0  = 25,
    GS0 = 26,
    Ab0 = 26,
    A0  = 28,
    AS0 = 29,
    Bb0 = 29,
    B0  = 31,

    C1  = 33,
    CS1 = 35,
    Db1 = 35,
    D1  = 37,
    DS1 = 39,
    Eb1 = 39,
    E1  = 41,
    F1  = 44,
    FS1 = 46,
    Gb1 = 46,
    G1  = 49,
    GS1 = 52,
    Ab1 = 52,
    A1  = 55,
    AS1 = 58,
    Bb1 = 58,
    B1  = 62,

    C2  = 65,
    CS2 = 69,
    Db2 = 69,
    D2  = 73,
    DS2 = 78,
    Eb2 = 78,
    E2  = 82,
    F2  = 87,
    FS2 = 93,
    Gb2 = 93,
    G2  = 98,
    GS2 = 104,
    Ab2 = 104,
    A2  = 110,
    AS2 = 117,
    Bb2 = 117,
    B2  = 123,

    C3  = 131,
    CS3 = 139,
    Db3 = 139,
    D3  = 147,
    DS3 = 156,
    Eb3 = 156,
    E3  = 165,
    F3  = 175,
    FS3 = 185,
    Gb3 = 185,
    G3  = 196,
    GS3 = 208,
    Ab3 = 208,
    A3  = 220,
    AS3 = 233,
    Bb3 = 233,
    B3  = 247,

    C4  = 262,
    CS4 = 277,
    Db4 = 277,
    D4  = 294,
    DS4 = 311,
    Eb4 = 311,
    E4  = 330,
    F4  = 349,
    FS4 = 370,
    Gb4 = 370,
    G4  = 392,
    GS4 = 415,
    Ab4 = 415,
    A4  = 440,
    AS4 = 466,
    Bb4 = 466,
    B4  = 494,

    C5  = 523,
    CS5 = 554,
    Db5 = 554,
    D5  = 587,
    DS5 = 622,
    Eb5 = 622,
    E5  = 659,
    F5  = 698,
    FS5 = 740,
    Gb5 = 740,
    G5  = 784,
    GS5 = 831,
    Ab5 = 831,
    A5  = 880,
    AS5 = 932,
    Bb5 = 932,
    B5  = 988,

    C6  = 1047,
    CS6 = 1109,
    Db6 = 1109,
    D6  = 1175,
    DS6 = 1245,
    Eb6 = 1245,
    E6  = 1319,
    F6  = 1397,
    FS6 = 1480,
    Gb6 = 1480,
    G6  = 1568,
    GS6 = 1661,
    Ab6 = 1661,
    A6  = 1760,
    AS6 = 1865,
    Bb6 = 1865,
    B6  = 1976,

    C7  = 2093,
    CS7 = 2217,
    Db7 = 2217,
    
    D7  = 2349,
    DS7 = 2489,
    Eb7 = 2489,
    E7  = 2637,
    F7  = 2794,
    FS7 = 2960,
    Gb7 = 2960,
    G7  = 3136,
    GS7 = 3322,
    Ab7 = 3322,
    A7  = 3520,
    AS7 = 3729,
    Bb7 = 3729,
    B7  = 3951,

    C8  = 4186
};

enum NoteType {
	WHOLE,
	HALF,
	QUARTER,
	EIGHTH,
	SIXTEENTH
};

class Buzzer {
    int pin;
    int tempo;
    BuzzerType buzzerType;
    
    double getDuration(NoteType noteType, bool isDotted);

public:
    Buzzer(int p, BuzzerType bt);
    void setPin(int p);
    void setBuzzerType(BuzzerType bt);
    void play(Notes note, NoteType noteType, bool isDotted);
    void off();
};

#endif
