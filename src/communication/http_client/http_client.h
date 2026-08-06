#ifndef HTTP_CLIENT_H
#define HTTP_CLIENT_H

#include <Arduino.h>

class HttpClient
{
public:
    void begin();

    bool postJson(const String& json);

private:
    String buildUrl() const;
};

#endif