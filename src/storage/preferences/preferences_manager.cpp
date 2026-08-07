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