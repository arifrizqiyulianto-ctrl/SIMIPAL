#include "serial_logger.h"

#include <Arduino.h>

void SerialLogger::begin()
{
    Serial.begin(115200);
}

void SerialLogger::print(const SensorData& data)
{
    printSensor("PH Voltage", data.ph, "V", 3);

    printSensor("Temperature", data.temperature, "C", 2);

    printSensor("TDS Voltage", data.tds, "V", 3);

    printSensor("Distance", data.waterLevel, "cm", 1);

    Serial.println("----------------------------------------");
}

void SerialLogger::printSensor(
    const char* name,
    const SensorReading& reading,
    const char* unit,
    uint8_t decimals)
{
    Serial.print(name);
    Serial.print(" : ");

    if (reading.valid)
    {
        Serial.print(reading.value, decimals);
        Serial.print(" ");
        Serial.println(unit);
    }
    else
    {
        Serial.println("INVALID");
    }
}