#ifndef SERIAL_LOGGER_H
#define SERIAL_LOGGER_H

#include "core/sensor_data.h"

class SerialLogger
{
public:
    void begin();

    void print(const SensorData& data);
};

#endif