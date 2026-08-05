#include "ph_sensor.h"

#include <Arduino.h>

#include "core/config_board.h"

void PhSensor::begin()
{
    analogReadResolution(12);
    analogSetPinAttenuation(PH_PIN, ADC_11db);
}

SensorReading PhSensor::read()
{
    SensorReading reading{};

    const int adc = analogRead(PH_PIN);

    reading.value = (static_cast<float>(adc) / 4095.0f) * 3.3f;
    reading.valid = true;

    return reading;
}