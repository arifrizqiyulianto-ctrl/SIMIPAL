#include <Arduino.h>
#include "core/config_board.h"
#include "services/data_aggregator/data_aggregator.h"
#include "utils/serial_logger/serial_logger.h"
#include "communication/json_builder/json_builder.h"
#include "communication/wifi_manager/wifi_manager.h"
#include "communication/http_client/http_client.h"


DataAggregator dataAggregator;
SerialLogger logger;
JsonBuilder jsonBuilder;
WiFiManager wifiManager;
HttpClient httpClient;

void setup()
{

    logger.begin();
    wifiManager.begin();
    httpClient.begin();
    
    dataAggregator.begin();
    Serial.println();
Serial.println("Connecting to WiFi...");

if (wifiManager.connect())
{
    Serial.println("WiFi Connected");
    Serial.print("IP Address : ");
    Serial.println(wifiManager.ipAddress());

    Serial.print("RSSI : ");
    Serial.print(wifiManager.rssi());
    Serial.println(" dBm");
}
else
{
    Serial.println("WiFi Connection Failed");
}

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

    String json = jsonBuilder.build(data);

    String response;

    httpClient.postJson(json, response);

    Serial.println(json);

    logger.print(data);

    delay(1000);
}