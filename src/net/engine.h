#pragma once
#include <event.h>

enum EngineStatus {
    ENGINE_STATUS_UNKNOWN = 0,
    ENGINE_STATUS_RUNNING = 1,
    ENGINE_STATUS_STOPPING = 2,
    ENGINE_STATUS_EXITTING = 3,
};


class Engine {
    public:
        Engine();
        ~Engine();

    public:
        virtual bool init();
        virtual void run();
        virtual void stop();
        void destory();

    protected:
        event_base* m_ev_base;
        event* m_ev_signal;
        EngineStatus m_status;
};