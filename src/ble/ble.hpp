#pragma once

#include <Arduino.h>
#include <bluefruit.h>

void ble_init(char *name);
void ble_notifyHR(uint8_t val);

bool connected();

void connect_cb(uint16_t conn_handle);
void disconnect_cb(uint16_t conn_handle, uint8_t reason);
