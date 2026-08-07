#ifndef WIFI_MANAGER_H
#define WIFI_MANAGER_H

#include <Arduino.h>
#include <WiFi.h>

class WiFiManager
{
public:
    void begin();

    bool connect();

    bool connect(const String& ssid,
                 const String& password);

    void disconnect();

    bool isConnected() const;

    String ipAddress() const;

    int32_t rssi() const;
};

#endif // WIFI_MANAGER_H