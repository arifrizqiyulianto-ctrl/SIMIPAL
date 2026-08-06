#ifndef JSON_BUILDER_H
#define JSON_BUILDER_H

#include <Arduino.h>

#include "core/sensor_data.h"

class JsonBuilder
{
public:
    String build(const SensorData& data);
};

#endif // JSON_BUILDER_H