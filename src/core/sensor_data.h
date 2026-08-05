#ifndef SENSOR_DATA_H
#define SENSOR_DATA_H

struct SensorReading
{
    float value;
    bool valid;
};

struct SensorData
{
    SensorReading ph;
    SensorReading tds;
    SensorReading temperature;
    SensorReading waterLevel;
};

#endif // SENSOR_DATA_H