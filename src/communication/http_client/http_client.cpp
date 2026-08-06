#include "http_client.h"

#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>

#include "core/config_network.h"

void HttpClient::begin()
{
}

String HttpClient::buildUrl() const
{
    String protocol = SERVER_USE_HTTPS ? "https://" : "http://";

    return protocol +
           String(SERVER_HOST) +
           ":" +
           String(SERVER_PORT) +
           String(SERVER_ENDPOINT);
}

bool HttpClient::postJson(const String& json, String& response)
{
    if (WiFi.status() != WL_CONNECTED)
{
    response = "WiFi not connected";
    return false;
}
    response = "";

    HTTPClient http;

    http.begin(buildUrl());

    http.addHeader("Content-Type", "application/json");

    const int httpCode = http.POST(json);

    if (httpCode > 0)
    {
        response = http.getString();

        Serial.print("HTTP Code : ");
        Serial.println(httpCode);

        http.end();

        return (httpCode == HTTP_CODE_OK);
    }

    Serial.print("HTTP Error : ");
    Serial.println(http.errorToString(httpCode));

    http.end();

    return false;
}