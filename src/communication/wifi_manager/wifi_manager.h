#ifndef WIFI_MANAGER_H
#define WIFI_MANAGER_H

#include <Arduino.h>
#include <WiFi.h>

class WiFiManager
{
public:
    void begin();

    bool connect();

    void disconnect();

    bool isConnected() const;

    String ipAddress() const;

    int32_t rssi() const;
};

#endif // WIFI_MANAGER_H