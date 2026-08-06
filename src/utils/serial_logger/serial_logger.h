#ifndef SERIAL_LOGGER_H
#define SERIAL_LOGGER_H

#include <Arduino.h>
#include "core/sensor_data.h"

class SerialLogger
{
public:
    void begin();

    void print(const SensorData& data);

private:
    void printSensor(
        const char* name,
        const SensorReading& reading,
        const char* unit,
        uint8_t decimals = 2);
};

#endif // SERIAL_LOGGER_H