#include "game_engine.h"
#include "time_helper.h"


GameEngine::GameEngine() {

}

GameEngine::~GameEngine() {
    destory();
}

bool GameEngine::init() {
    if (!Engine::init()) {
        return false;
    }

    m_ev_timer = event_new(m_ev_base, -1, EV_PERSIST|EV_TIMEOUT, [](evutil_socket_t fd, short event, void *args) {
        GameEngine* ge = (GameEngine*) args;
        ge->timer_200ms();
    }, this);

    if (m_ev_timer == nullptr) {
        return false;
    }

    // 200ms执行一次
    timeval tv = {0, 200 * 1000};
    evtimer_add(m_ev_timer, &tv);

    return true;
}

void GameEngine::destory() {
    SAFE_DELETE(m_ev_timer);
}

void GameEngine::timer_200ms() {
    CSingleton<common::TimeHelper>::get()->update_time();
    std::cout << "time call: " << CSingleton<common::TimeHelper>::get()->ts() << std::endl;
}