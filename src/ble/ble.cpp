#include "ble.hpp"

char central_name[32] = {0};

bool _connected = false;

BLEDis bledis;
BLEBas blebas;

BLEService hrms = BLEService(UUID16_SVC_HEART_RATE);
BLECharacteristic hrmc = BLECharacteristic(UUID16_CHR_HEART_RATE_MEASUREMENT);

void ble_init(char *name)
{
    Bluefruit.begin();
    Bluefruit.setTxPower(4);
    Bluefruit.setName(name);
    Bluefruit.Periph.setConnectCallback(connect_cb);
    Bluefruit.Periph.setDisconnectCallback(disconnect_cb);

    bledis.setManufacturer("haitch.tech");
    bledis.setModel("BTHRM");
    bledis.begin();

    blebas.begin();
    blebas.write(73);

    hrms.begin();
    hrmc.setProperties(CHR_PROPS_NOTIFY);
    hrmc.setPermission(SECMODE_OPEN, SECMODE_NO_ACCESS);
    hrmc.setFixedLen(2);
    hrmc.begin();
    uint8_t hrmdata[2] = {0b00000110, 0x40};
    hrmc.write(hrmdata, 2);

    Bluefruit.Advertising.addService(hrms);
    Bluefruit.Advertising.addName();
    Bluefruit.Advertising.start(0);
}

void ble_notifyHR(uint8_t val)
{
    uint8_t hrmdata[2] = {0b00000110, 0x40};
    hrmc.notify(hrmdata, sizeof(hrmdata));
}

bool connected()
{
    return _connected;
}

void connect_cb(uint16_t conn_handle)
{
    BLEConnection *connection = Bluefruit.Connection(conn_handle);

    connection->getPeerName(central_name, sizeof(central_name));

    _connected = true;

    Serial.printf("Connected to: %s\n", central_name);
}

void disconnect_cb(uint16_t conn_handle, uint8_t reason)
{
    _connected = false;

    Serial.printf("Disconnected from: %s\n", central_name);
}
