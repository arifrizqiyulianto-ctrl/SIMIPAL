#ifndef CONFIG_NETWORK_H
#define CONFIG_NETWORK_H

#include <stdint.h>

// ============================================================================
// WiFi Configuration
// ============================================================================

constexpr char WIFI_SSID[] = "YOUR_WIFI";
constexpr char WIFI_PASSWORD[] = "YOUR_PASSWORD";

constexpr uint32_t WIFI_CONNECT_TIMEOUT_MS = 15000;

// ============================================================================
// Server Configuration
// ============================================================================

constexpr char SERVER_HOST[] = "192.168.102.10";

constexpr uint16_t SERVER_PORT = 80;

constexpr char SERVER_ENDPOINT[] = "/simipal/api.php";

constexpr bool SERVER_USE_HTTPS = false;

#endif