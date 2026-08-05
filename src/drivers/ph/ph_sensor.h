#ifndef PH_SENSOR_H
#define PH_SENSOR_H

#include "core/sensor_data.h"

class PhSensor
{
public:
    void begin();

    SensorReading read();
};

#endif // PH_SENSOR_H