#ifndef TDS_SENSOR_H
#define TDS_SENSOR_H

#include "core/sensor_data.h"

class TdsSensor
{
public:
    void begin();

    SensorReading read(float waterTemperature);
};

#endif // TDS_SENSOR_H