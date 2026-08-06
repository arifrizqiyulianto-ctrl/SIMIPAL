#include "data_aggregator.h"

void DataAggregator::begin()
{
    sensorManager_.begin();
}

SensorData DataAggregator::collect()
{
    return sensorManager_.read();
}