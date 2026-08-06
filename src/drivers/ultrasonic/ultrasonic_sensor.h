#ifndef ULTRASONIC_SENSOR_H
#define ULTRASONIC_SENSOR_H

#include "core/sensor_data.h"

class UltrasonicSensor
{
public:
    void begin();

    SensorReading read();
};

#endif // ULTRASONIC_SENSOR_H