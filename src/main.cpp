#include <Arduino.h>
#include "core/config_board.h"
#include "drivers/ph/ph_sensor.h"
#include "drivers/ds18b20/ds18b20_sensor.h"


PhSensor phSensor;
Ds18b20Sensor temperatureSensor(DS18B20_PIN);

void setup()
{
    Serial.begin(115200);
    
    phSensor.begin();
    temperatureSensor.begin();

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

    Serial.println("----------------------------------------");

    delay(1000);
}  