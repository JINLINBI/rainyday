#include "time_helper.h"
COMMON_NPS_START

uint32_t TimeHelper::ts() {
    return m_current_ts_ms / 1000;
}

uint64_t TimeHelper::ts_ms() {
    return m_current_ts_ms;
}

void TimeHelper::update_time() {
    auto now = std::chrono::high_resolution_clock::now().time_since_epoch();
    auto millisecs = std::chrono::duration_cast<std::chrono::milliseconds>(now);
    m_current_ts_ms = millisecs.count();
}

COMMON_NPS_END