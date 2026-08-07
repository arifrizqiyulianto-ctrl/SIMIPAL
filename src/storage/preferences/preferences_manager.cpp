#include "storage/preferences/preferences_manager.h"

#include <Preferences.h>

namespace
{
    Preferences preferences;
    constexpr const char* NAMESPACE_NAME = "simipal";
}

void PreferencesManager::begin()
{
    preferences.begin(NAMESPACE_NAME, false);
}

bool PreferencesManager::saveString(const char* key,
                                    const String& value)
{
    return preferences.putString(key, value) > 0;
}

String PreferencesManager::loadString(const char* key,
                                      const String& defaultValue)
{
    return preferences.getString(key, defaultValue);
}

bool PreferencesManager::saveInt(const char* key,
                                 int value)
{
    return preferences.putInt(key, value) > 0;
}

int PreferencesManager::loadInt(const char* key,
                                int defaultValue)
{
    return preferences.getInt(key, defaultValue);
}
bool PreferencesManager::saveBool(const char* key,
                                  bool value)
{
return preferences.putBool(key, value) > 0;
}

bool PreferencesManager::loadBool(const char* key,
                                  bool defaultValue)
{
    return preferences.getBool(key, defaultValue);
}

bool PreferencesManager::saveFloat(const char* key,
                                   float value)
{
    return preferences.putFloat(key, value) > 0;
}

float PreferencesManager::loadFloat(const char* key,
                                    float defaultValue)
{
    return preferences.getFloat(key, defaultValue);
}

bool PreferencesManager::saveUInt(const char* key,
                                  uint32_t value)
{
    return preferences.putUInt(key, value) > 0;
}

uint32_t PreferencesManager::loadUInt(const char* key,
                                      uint32_t defaultValue)
{
    return preferences.getUInt(key, defaultValue);
}