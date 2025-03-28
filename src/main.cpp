#include <Arduino.h>
#include "ble/ble.hpp"
#include "hrm/hrm.hpp"

char *BLEName = (char *)"BTHRM";

void setup()
{
    ble_init(BLEName);
    hrm_init();

    Serial.begin(115200);
}

void loop()
{
    if (available() && connected())
        ble_notifyHR(hrm_update());

    delay(1000);
}
