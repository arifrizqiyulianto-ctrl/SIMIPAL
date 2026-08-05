#include "ds18b20_sensor.h"

Ds18b20Sensor::Ds18b20Sensor(uint8_t pin)
    : pin_(pin),
      oneWire_(pin),
      sensors_(&oneWire_)
{
}

void Ds18b20Sensor::begin()
{
    sensors_.begin();
}

SensorReading Ds18b20Sensor::read()
{
    SensorReading reading{};

    sensors_.requestTemperatures();

    const float temperature = sensors_.getTempCByIndex(0);

    reading.value = temperature;
    reading.valid = (temperature != DEVICE_DISCONNECTED_C);

    return reading;
}