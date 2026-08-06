#ifndef SENSOR_MANAGER_H
#define SENSOR_MANAGER_H

#include "core/sensor_data.h"
#include "core/config_board.h"

#include "drivers/ph/ph_sensor.h"
#include "drivers/tds/tds_sensor.h"
#include "drivers/ds18b20/ds18b20_sensor.h"
#include "drivers/ultrasonic/ultrasonic_sensor.h"

class SensorManager
{
public:
    void begin();

    SensorData readAll();

private:
    PhSensor phSensor_;

    Ds18b20Sensor temperatureSensor_{DS18B20_PIN};

    TdsSensor tdsSensor_;

    UltrasonicSensor ultrasonicSensor_;
};
#endif // SENSOR_MANAGER_H