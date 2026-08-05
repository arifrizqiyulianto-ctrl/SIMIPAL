#ifndef DS18B20_SENSOR_H
#define DS18B20_SENSOR_H

#include <Arduino.h>

#include "OneWire.h"
#include "DallasTemperature.h"

#include "core/sensor_data.h"

class Ds18b20Sensor
{
public:
    explicit Ds18b20Sensor(uint8_t pin);

    void begin();

    SensorReading read();

private:
    uint8_t pin_;

    OneWire oneWire_;
    DallasTemperature sensors_;
};

#endif // DS18B20_SENSOR_H