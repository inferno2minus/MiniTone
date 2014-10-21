/**
 * Project MiniTone Library
 * Description: Tone generator library for Arduino
 * Version: v1.0
 * Programmer: Kompanets Konstantin (aka I2M)
 *
 * Hardware setup: Buzzer module
 */

#ifndef MINITONE_H
#define MINITONE_H

#include "Arduino.h"

class MiniTone {
public:
  void begin(uint8_t);
  void play(uint8_t, ...);
  void play(uint16_t, uint32_t);
private:
  uint8_t _pin;
};

#endif
