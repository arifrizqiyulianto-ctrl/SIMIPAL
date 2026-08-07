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
    bool saveBool(const char* key, bool value);

    bool loadBool(const char* key,
                bool defaultValue = false);

    bool saveFloat(const char* key, float value);

    float loadFloat(const char* key,
                    float defaultValue = 0.0f);

    bool saveUInt(const char* key, uint32_t value);

    uint32_t loadUInt(const char* key,
                    uint32_t defaultValue = 0);
};

#endif