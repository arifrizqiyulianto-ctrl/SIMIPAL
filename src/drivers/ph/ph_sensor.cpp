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

    reading.value = static_cast<float>(analogRead(PH_PIN));
    reading.valid = true;

    return reading;
}