#include "sensor_manager.h"

void SensorManager::begin()
{
    phSensor_.begin();

    temperatureSensor_.begin();

    tdsSensor_.begin();

    ultrasonicSensor_.begin();
}

SensorData SensorManager::read()
{
    SensorData data{};

    data.ph = phSensor_.read();

    data.temperature = temperatureSensor_.read();

    float waterTemperature = 25.0f;

    if (data.temperature.valid)
    {
        waterTemperature = data.temperature.value;
    }

    data.tds = tdsSensor_.read(waterTemperature);

    data.waterLevel = ultrasonicSensor_.read();

    return data;
}