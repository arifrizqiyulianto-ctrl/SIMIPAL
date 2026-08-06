#include "json_builder.h"

#include <ArduinoJson.h>

String JsonBuilder::build(const SensorData& data)
{
    JsonDocument doc;

    doc["ph_voltage"] = data.ph.value;
    doc["temperature"] = data.temperature.value;
    doc["tds_voltage"] = data.tds.value;
    doc["water_level"] = data.waterLevel.value;

    String json;

    serializeJson(doc, json);

    return json;
}