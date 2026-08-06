#include "tds_sensor.h"

#include <Arduino.h>

#include "core/config_board.h"
#include "core/config_sensor.h"

void TdsSensor::begin()
{
    analogReadResolution(12);
    analogSetPinAttenuation(TDS_PIN, ADC_11db);
}

SensorReading TdsSensor::read(float waterTemperature)
{
    (void)waterTemperature;

    SensorReading reading{};

    uint32_t total = 0;

    for (uint8_t i = 0; i < TDS_SAMPLE_COUNT; ++i)
    {
        total += analogReadMilliVolts(TDS_PIN);
        delay(TDS_SAMPLE_DELAY_MS);
    }

    const float voltage =
    (static_cast<float>(total) /
     static_cast<float>(TDS_SAMPLE_COUNT)) /
    1000.0f;

    reading.value = voltage;
    reading.valid = true;

    return reading;
}