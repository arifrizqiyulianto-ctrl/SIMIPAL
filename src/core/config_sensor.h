#ifndef CONFIG_SENSOR_H
#define CONFIG_SENSOR_H

// ============================================================================
// PH Sensor Configuration
// ============================================================================

constexpr uint8_t PH_SAMPLE_COUNT = 10;
constexpr float PH_EMA_ALPHA = 0.10f;

// Nilai kalibrasi (sementara)
constexpr float PH7_VOLTAGE = 2.700f;
constexpr float PH_SLOPE = 0.05916f;

// ============================================================================
// TDS Sensor Configuration
// ============================================================================

constexpr uint8_t TDS_SAMPLE_COUNT = 50;

constexpr uint16_t TDS_SAMPLE_DELAY_MS = 5;

constexpr float TDS_CALIBRATION_SLOPE = 593.31f;

constexpr float TDS_CALIBRATION_OFFSET = -43.34f;

// ============================================================================
// Ultrasonic Sensor Configuration
// ============================================================================

constexpr uint32_t ULTRASONIC_TIMEOUT_US = 30000UL;

constexpr float SOUND_SPEED_CM_PER_US = 0.0343f;

constexpr uint16_t ULTRASONIC_TRIGGER_US = 10;

constexpr uint16_t ULTRASONIC_SETTLE_US  = 2;

#endif // CONFIG_SENSOR_H