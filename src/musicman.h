/*
 * MIT License
 *
 * Copyright (c) 2023 Leon Cotten
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#ifndef musicman_h
#define musicman_h

#include "Arduino.h"

enum BuzzerType: uint8_t {
  ACTIVE,
  PASSIVE
};

enum Notes : uint8_t {
    NOTE_C0 = 16,
    NOTE_CS0 = 17,
    NOTE_Db0 = 17,
    NOTE_D0 = 18,
    NOTE_DS0 = 19,
    NOTE_Eb0 = 19,
    NOTE_E0 = 21,
    NOTE_F0 = 22,
    NOTE_FS0 = 23,
    NOTE_Gb0 = 23,
    NOTE_G0 = 25,
    NOTE_GS0 = 26,
    NOTE_Ab0 = 26,
    NOTE_A0 = 28,
    NOTE_AS0 = 29,
    NOTE_Bb0 = 29,
    NOTE_B0 = 31,

    NOTE_C1 = 33,
    NOTE_CS1 = 35,
    NOTE_Db1 = 35,
    NOTE_D1 = 37,
    NOTE_DS1 = 39,
    NOTE_Eb1 = 39,
    NOTE_E1 = 41,
    NOTE_F1 = 44,
    NOTE_FS1 = 46,
    NOTE_Gb1 = 46,
    NOTE_G1 = 49,
    NOTE_GS1 = 52,
    NOTE_Ab1 = 52,
    NOTE_A1 = 55,
    NOTE_AS1 = 58,
    NOTE_Bb1 = 58,
    NOTE_B1 = 62,

    NOTE_C2 = 65,
    NOTE_CS2 = 69,
    NOTE_Db2 = 69,
    NOTE_D2 = 73,
    NOTE_DS2 = 78,
    NOTE_Eb2 = 78,
    NOTE_E2 = 82,
    NOTE_F2 = 87,
    NOTE_FS2 = 93,
    NOTE_Gb2 = 93,
    NOTE_G2 = 98,
    NOTE_GS2 = 104,
    NOTE_Ab2 = 104,
    NOTE_A2 = 110,
    NOTE_AS2 = 117,
    NOTE_Bb2 = 117,
    NOTE_B2 = 123,

    NOTE_C3 = 131,
    NOTE_CS3 = 139,
    NOTE_Db3 = 139,
    NOTE_D3 = 147,
    NOTE_DS3 = 156,
    NOTE_Eb3 = 156,
    NOTE_E3 = 165,
    NOTE_F3 = 175,
    NOTE_FS3 = 185,
    NOTE_Gb3 = 185,
    NOTE_G3 = 196,
    NOTE_GS3 = 208,
    NOTE_Ab3 = 208,
    NOTE_A3 = 220,
    NOTE_AS3 = 233,
    NOTE_Bb3 = 233,
    NOTE_B3 = 247,

    NOTE_C4 = 262,
    NOTE_CS4 = 277,
    NOTE_Db4 = 277,
    NOTE_D4 = 294,
    NOTE_DS4 = 311,
    NOTE_Eb4 = 311,
    NOTE_E4 = 330,
    NOTE_F4 = 349,
    NOTE_FS4 = 370,
    NOTE_Gb4 = 370,
    NOTE_G4 = 392,
    NOTE_GS4 = 415,
    NOTE_Ab4 = 415,
    NOTE_A4 = 440,
    NOTE_AS4 = 466,
    NOTE_Bb4 = 466,
    NOTE_B4 = 494,

    NOTE_C5 = 523,
    NOTE_CS5 = 554,
    NOTE_Db5 = 554,
    NOTE_D5 = 587,
    NOTE_DS5 = 622,
    NOTE_Eb5 = 622,
    NOTE_E5 = 659,
    NOTE_F5 = 698,
    NOTE_FS5 = 740,
    NOTE_Gb5 = 740,
    NOTE_G5 = 784,
    NOTE_GS5 = 831,
    NOTE_Ab5 = 831,
    NOTE_A5 = 880,
    NOTE_AS5 = 932,
    NOTE_Bb5 = 932,
    NOTE_B5 = 988,

    NOTE_C6 = 1047,
    NOTE_CS6 = 1109,
    NOTE_Db6 = 1109,
    NOTE_D6 = 1175,
    NOTE_DS6 = 1245,
    NOTE_Eb6 = 1245,
    NOTE_E6 = 1319,
    NOTE_F6 = 1397,
    NOTE_FS6 = 1480,
    NOTE_Gb6 = 1480,
    NOTE_G6 = 1568,
    NOTE_GS6 = 1661,
    NOTE_Ab6 = 1661,
    NOTE_A6 = 1760,
    NOTE_AS6 = 1865,
    NOTE_Bb6 = 1865,
    NOTE_B6 = 1976,

    NOTE_C7 = 2093,
    NOTE_CS7 = 2217,
    NOTE_Db7 = 2217,

    NOTE_D7 = 2349,
    NOTE_DS7 = 2489,
    NOTE_Eb7 = 2489,
    NOTE_E7 = 2637,
    NOTE_F7 = 2794,
    NOTE_FS7 = 2960,
    NOTE_Gb7 = 2960,
    NOTE_G7 = 3136,
    NOTE_GS7 = 3322,
    NOTE_Ab7 = 3322,
    NOTE_A7 = 3520,
    NOTE_AS7 = 3729,
    NOTE_Bb7 = 3729,
    NOTE_B7 = 3951,

    NOTE_C8 = 4186
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
