#ifndef PREFERENCES_MANAGER_H
#define PREFERENCES_MANAGER_H

#include <Arduino.h>

class PreferencesManager
{
public:
    void begin();

    bool saveString(const char* key, const String& value);

    String loadString(const char* key,
                      const String& defaultValue = "");

    bool saveInt(const char* key, int value);

    int loadInt(const char* key,
                int defaultValue = 0);
};

#endif