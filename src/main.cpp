#include <Arduino.h>

void setup()
{
    Serial.begin(115200);

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
    // Firmware utama akan dikembangkan bertahap.
}