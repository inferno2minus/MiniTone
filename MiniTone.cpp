/**
 * Project MiniTone Library
 * Description: Tone generator library for Arduino
 * Version: v1.0
 * Programmer: Kompanets Konstantin (aka I2M)
 *
 * Hardware setup: Buzzer module
 */

#include "MiniTone.h"

void MiniTone::begin(uint8_t pin) {
  _pin = pin;
  pinMode(_pin, OUTPUT);
}

void MiniTone::play(uint8_t count, ...) {
  va_list ap;
  va_start(ap, count);

  while (count > 0) {
    uint16_t frequency = va_arg(ap, uint16_t);
    uint16_t duration = va_arg(ap, uint16_t);
    play(frequency, duration);
    count--;
  }
  va_end(ap);
}

void MiniTone::play(uint16_t frequency, uint32_t duration) {
  uint8_t flag;
  int32_t toggle_count = 2 * frequency * duration / 1000;
  int32_t half_cycle = 1000000L / (frequency * 2);

  while (toggle_count--) {
    //Toggle the pin
    flag = !flag;
    digitalWrite(_pin, flag ? LOW : HIGH);
    //Delay a half cycle
    delayMicroseconds(half_cycle);
  }
  digitalWrite(_pin, LOW); //Keep pin low after stop
}
