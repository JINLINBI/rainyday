
#pragma once
#include <iostream>
#include "engine.h"
#include "common.h"


class GameEngine: public Engine {
	public:
		GameEngine();
		virtual ~GameEngine();

	public:
		virtual bool init();
		void destory();

		void timer_200ms();

	private:
		event* m_ev_timer;
};