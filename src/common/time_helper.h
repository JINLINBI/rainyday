#pragma once
#include <singleton.h>
#include <chrono>
#include "common.h"

COMMON_NPS_START
class TimeHelper {
    public:
        uint32_t ts();
        uint64_t ts_ms();

        void update_time();

    private:
        uint64_t m_current_ts_ms;
};

COMMON_NPS_END
