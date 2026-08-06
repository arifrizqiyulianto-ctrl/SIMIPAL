#include <Arduino.h>
#include "core/config_board.h"
#include "services/sensor_manager/sensor_manager.h"


SensorManager sensorManager;

void setup()
{
    Serial.begin(115200);
    
    sensorManager.begin();

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
SensorData data = sensorManager.read();

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

    delay(1000);
}  