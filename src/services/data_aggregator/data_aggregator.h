#ifndef DATA_AGGREGATOR_H
#define DATA_AGGREGATOR_H

#include "core/sensor_data.h"
#include "services/sensor_manager/sensor_manager.h"

class DataAggregator
{
public:
    void begin();

    SensorData collect();

private:
    SensorManager sensorManager_;
};

#endif