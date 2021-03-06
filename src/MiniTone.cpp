/**
 * Project:     MiniTone Library
 * Description: Tone generator library for Arduino
 * Version:     v1.0
 * Author:      Kompanets Konstantin (aka I2M)
 */

#include "MiniTone.h"

void MiniTone::begin(uint8_t buzzer_pin) {
  _buzzer_pin = buzzer_pin;
  pinMode(_buzzer_pin, OUTPUT);
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

void MiniTone::play(uint16_t frequency, uint16_t duration) {
  uint16_t toggle_count = (uint32_t)frequency * duration / 1000;
  uint16_t half_cycle = 1000000L / frequency / 2;

  while (toggle_count--) {
    digitalWrite(_buzzer_pin, HIGH);
    delayMicroseconds(half_cycle);
    digitalWrite(_buzzer_pin, LOW);
    delayMicroseconds(half_cycle);
  }
}
