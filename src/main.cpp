#include <Arduino.h>
#include "core/config_board.h"
#include "services/data_aggregator/data_aggregator.h"
#include "utils/serial_logger/serial_logger.h"


DataAggregator dataAggregator;
SerialLogger logger;

void setup()
{

    logger.begin();
    
    dataAggregator.begin();

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
    SensorData data = dataAggregator.collect();

    logger.print(data);

    delay(1000);
}