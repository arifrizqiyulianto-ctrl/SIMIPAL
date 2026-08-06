#include "ultrasonic_sensor.h"

#include <Arduino.h>

#include "core/config_board.h"
#include "core/config_sensor.h"

void UltrasonicSensor::begin()
{
    pinMode(JSN_TRIGGER_PIN, OUTPUT);
    pinMode(JSN_ECHO_PIN, INPUT);

    digitalWrite(JSN_TRIGGER_PIN, LOW);
}

SensorReading UltrasonicSensor::read()
{
    SensorReading reading{};

    // Pastikan trigger LOW
    digitalWrite(JSN_TRIGGER_PIN, LOW);
    delayMicroseconds(ULTRASONIC_SETTLE_US);

    // Trigger 10 µs
    digitalWrite(JSN_TRIGGER_PIN, HIGH);
    delayMicroseconds(ULTRASONIC_TRIGGER_US);
    digitalWrite(JSN_TRIGGER_PIN, LOW);

    const unsigned long duration =
        pulseIn(JSN_ECHO_PIN, HIGH, ULTRASONIC_TIMEOUT_US);

    if (duration == 0)
    {
        reading.valid = false;
        return reading;
    }

    reading.value =
        (duration * SOUND_SPEED_CM_PER_US) / 2.0f;

    reading.valid = true;

    return reading;
}