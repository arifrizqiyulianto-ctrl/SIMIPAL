#include "http_client.h"

#include <Arduino.h>

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
    (void)json;

    response = "";

    Serial.print("HTTP URL : ");
    Serial.println(buildUrl());

    return false;
}