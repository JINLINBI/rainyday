#include <iostream>
#include <signal.h>

#include "common.h"
#include "engine.h"

Engine::Engine() {

}

Engine::~Engine() {
    destory();
}

bool Engine::init() {
    m_ev_base = event_base_new();
    if (m_ev_base == nullptr) {
        return false;
    }

    // 注册退出信号
    m_ev_signal = evsignal_new(m_ev_base, SIGINT, [](evutil_socket_t fd, short event, void *args){
        Engine* eg = (Engine*) args;
        eg->stop();
    }, this);

    return m_ev_base != nullptr;
}

void Engine::run() {
    if (m_ev_base == nullptr) {
        std::cout << "init engine first!" << std::endl;
        return;
    }

    m_status = ENGINE_STATUS_RUNNING;
    while (true) {
        event_base_dispatch(m_ev_base);
        if (m_status == ENGINE_STATUS_STOPPING) {
            break;
        }
    }
    m_status = ENGINE_STATUS_EXITTING;
    event_base_free(m_ev_base);
    m_ev_base = nullptr;
}

void Engine::stop() {
    m_status = ENGINE_STATUS_STOPPING;
    std::cout << "exitting ..." << std::endl;
}

void Engine::destory() {
    SAFE_DELETE(m_ev_signal);
    // SAFE_DELETE(m_ev_base);
    event_base_free(m_ev_base);
}