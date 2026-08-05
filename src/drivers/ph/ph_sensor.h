#ifndef PH_SENSOR_H
#define PH_SENSOR_H

#include "core/sensor_data.h"

class PhSensor
{
public:
    void begin();

    SensorReading read();

private:
    float filteredVoltage_ = 0.0f;
    bool filterInitialized_ = false;
};

#endif // PH_SENSOR_H