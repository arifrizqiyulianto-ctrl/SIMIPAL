#include <Arduino.h>
#include "drivers/ph/ph_sensor.h"

PhSensor phSensor;

void setup()
{
    Serial.begin(115200);
    
    phSensor.begin();

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
    SensorReading reading = phSensor.read();

    Serial.print("Voltage : ");
    Serial.print(reading.value, 3);
    Serial.println(" V");

    delay(1000);
}   