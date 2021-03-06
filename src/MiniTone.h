/**
 * Project:     MiniTone Library
 * Description: Tone generator library for Arduino
 * Version:     v1.0
 * Author:      Kompanets Konstantin (aka I2M)
 */

#ifndef MINITONE_H
#define MINITONE_H

#include "Arduino.h"

class MiniTone {
public:
  void begin(uint8_t buzzer_pin);
  void play(uint8_t count, ...);
  void play(uint16_t frequency, uint16_t duration);
private:
  uint8_t _buzzer_pin;
};

#endif
