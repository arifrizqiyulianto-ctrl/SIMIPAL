#include "wifi_manager.h"

#include "core/config_network.h"

void WiFiManager::begin()
{
    WiFi.mode(WIFI_STA);
}

bool WiFiManager::connect()
{
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

    const uint32_t startTime = millis();

    while (WiFi.status() != WL_CONNECTED)
    {
        if (millis() - startTime > WIFI_CONNECT_TIMEOUT_MS)
        {
            return false;
        }

        delay(250);
    }

    return true;
}

void WiFiManager::disconnect()
{
    WiFi.disconnect(true);
}

bool WiFiManager::isConnected() const
{
    return WiFi.status() == WL_CONNECTED;
}

String WiFiManager::ipAddress() const
{
    return WiFi.localIP().toString();
}

int32_t WiFiManager::rssi() const
{
    return WiFi.RSSI();
}