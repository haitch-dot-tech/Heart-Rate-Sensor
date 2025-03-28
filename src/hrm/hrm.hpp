#pragma once

#include <Arduino.h>
#include <Wire.h>
// #include <MAX30102.h>

void hrm_init();
uint8_t hrm_update();

bool available();
