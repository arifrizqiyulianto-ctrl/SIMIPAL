#include <Arduino.h>

#include "core/config_board.h"
#include "core/config_network.h"
#include "core/config_storage.h"

#include "storage/preferences/preferences_manager.h"

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
PreferencesManager preferencesManager;

void setup()
{
    logger.begin();

    preferencesManager.begin();

    wifiManager.begin();

    httpClient.begin();

    dataAggregator.begin();

    Serial.println();

    String ssid = preferencesManager.loadString(
        PREF_WIFI_SSID,
        "");

    if (ssid.isEmpty())
    {
        preferencesManager.saveString(
            PREF_WIFI_SSID,
            WIFI_SSID);

        ssid = WIFI_SSID;
    }

    String password = preferencesManager.loadString(
        PREF_WIFI_PASSWORD,
        "");

    if (password.isEmpty())
    {
        preferencesManager.saveString(
            PREF_WIFI_PASSWORD,
            WIFI_PASSWORD);

        password = WIFI_PASSWORD;
    }

    Serial.print("Loaded SSID : ");
    Serial.println(ssid);

    Serial.println();
    Serial.println("Connecting to WiFi...");

    if (wifiManager.connect(ssid, password))
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

    if (httpClient.postJson(json, response))
    {
        Serial.println("POST SUCCESS");
    }
    else
    {
        Serial.println("POST FAILED");
    }

    Serial.println(response);

    logger.print(data);

    delay(1000);
}