#pragma once
#define COMMON_NPS_START namespace common {
#define COMMON_NPS_END }

#define SAFE_DELETE(ptr)\
    do { \
        if (ptr != nullptr) {\
            delete ptr; \
            ptr = nullptr; \
        } \
    } while(0);

#define SAFE_DELELET_ARRAY(array) \
    do { \
        if (array != nullptr) { \
            delete[] array; \
            array = nullptr; \
        } \
    } while(0);
