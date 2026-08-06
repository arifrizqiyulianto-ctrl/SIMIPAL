#include "sensor_manager.h"

void SensorManager::begin()
{
    phSensor_.begin();

    temperatureSensor_.begin();

    tdsSensor_.begin();

    ultrasonicSensor_.begin();
}

SensorData SensorManager::readAll()
{
    SensorData data{};

    data.ph = phSensor_.read();

    data.temperature = temperatureSensor_.read();

    data.tds = tdsSensor_.read(data.temperature.value);

    data.waterLevel = ultrasonicSensor_.read();

    return data;
}