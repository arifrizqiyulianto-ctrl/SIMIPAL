#include <Arduino.h>
#include "core/config_board.h"
#include "drivers/ph/ph_sensor.h"
#include "drivers/ds18b20/ds18b20_sensor.h"
#include "drivers/tds/tds_sensor.h"
#include "drivers/ultrasonic/ultrasonic_sensor.h"


PhSensor phSensor;
Ds18b20Sensor temperatureSensor(DS18B20_PIN);
TdsSensor tdsSensor;
UltrasonicSensor ultrasonicSensor;

void setup()
{
    Serial.begin(115200);
    
    phSensor.begin();
    temperatureSensor.begin();
    tdsSensor.begin();
    ultrasonicSensor.begin();

    // Memberi waktu Serial siap
    delay(1000);

    Serial.println();
    Serial.println("========================================");
    Serial.println(" SIMIPAL IoT LABKESDA");
    Serial.println(" Firmware started");
    Serial.println("========================================");
}

void loop()
{
    SensorReading phReading = phSensor.read();
    SensorReading temperatureReading = temperatureSensor.read();
    SensorReading tdsReading = tdsSensor.read(temperatureReading.value);
    SensorReading distanceReading = ultrasonicSensor.read();

    Serial.print("PH Voltage : ");
    Serial.print(phReading.value, 3);
    Serial.println(" V");

    if (temperatureReading.valid)
    {
        Serial.print("Temperature : ");
        Serial.print(temperatureReading.value, 2);
        Serial.println(" C");
    }
    else
    {
        Serial.println("Temperature : INVALID");
    }

    Serial.print("TDS Voltage : ");
    Serial.print(tdsReading.value, 3);
    Serial.println(" V");

    if (distanceReading.valid)
    {
        Serial.print("Distance : ");
        Serial.print(distanceReading.value, 1);
        Serial.println(" cm");
    }
    else
    {
        Serial.println("Distance : INVALID");
    }

    Serial.println("----------------------------------------");

    delay(1000);
}  