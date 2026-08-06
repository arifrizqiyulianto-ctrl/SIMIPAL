#include "serial_logger.h"

#include <Arduino.h>

void SerialLogger::begin()
{
    Serial.begin(115200);
}

void SerialLogger::print(const SensorData& data)
{
    Serial.print("PH Voltage : ");
    Serial.print(data.ph.value, 3);
    Serial.println(" V");

    if (data.temperature.valid)
    {
        Serial.print("Temperature : ");
        Serial.print(data.temperature.value, 2);
        Serial.println(" C");
    }
    else
    {
        Serial.println("Temperature : INVALID");
    }

    Serial.print("TDS Voltage : ");
    Serial.print(data.tds.value, 3);
    Serial.println(" V");

    if (data.waterLevel.valid)
    {
        Serial.print("Distance : ");
        Serial.print(data.waterLevel.value, 1);
        Serial.println(" cm");
    }
    else
    {
        Serial.println("Distance : INVALID");
    }

    Serial.println("----------------------------------------");
}