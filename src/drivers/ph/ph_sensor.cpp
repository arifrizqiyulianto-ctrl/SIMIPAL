#include "ph_sensor.h"

#include <Arduino.h>

#include "core/config_board.h"
#include "core/config_sensor.h"

void PhSensor::begin()
{
    analogReadResolution(12);
    analogSetPinAttenuation(PH_PIN, ADC_11db);
}

SensorReading PhSensor::read()
{
    SensorReading reading{};

    uint32_t total = 0;

    for (uint8_t i = 0; i < PH_SAMPLE_COUNT; ++i)
    {
        total += analogRead(PH_PIN);
    }

    const float averageAdc =
        static_cast<float>(total) / static_cast<float>(PH_SAMPLE_COUNT);

    reading.value = (averageAdc / 4095.0f) * 3.3f;
    reading.valid = true;

    return reading;
}