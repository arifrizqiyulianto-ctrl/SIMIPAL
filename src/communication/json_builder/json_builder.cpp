#include "json_builder.h"

#include <ArduinoJson.h>

String JsonBuilder::build(const SensorData& data)
{
    JsonDocument doc;

    doc["ph"] = data.ph.value;
    doc["temperature"] = data.temperature.value;
    doc["tds"] = data.tds.value;
    doc["water_level"] = data.waterLevel.value;

    String json;

    serializeJson(doc, json);

    return json;
}