#include "hrm.hpp"

bool _available = false;

// TwoWire wire(NRF_TWIM0, nullptr, SPIM0_SPIS0_TWIM0_TWIS0_SPI0_TWI0_IRQn, 4, 5);

void hrm_init()
{
    // wire.begin(0x57);
    _available = true;
    
    // for (int addr = 1; addr < 128; addr++)
    // {
    //     wire.beginTransmission(addr);
    //     if (0 == wire.endTransmission())
    //     {
    //         Serial.print("Found: 0x");
    //         Serial.print(addr, HEX);
    //         Serial.println();
    //     }
    // }
    // Serial.print("Finished scan\n");
}

uint8_t hrm_update()
{
    return 80;
}

bool available()
{
    return _available;
}
