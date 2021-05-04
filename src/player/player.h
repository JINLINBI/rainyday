#pragma once
#include <map>
#include <string>

class Player {
    public:
        Player();
        ~Player();

        void set_name(std::string name);
        std::string get_name();
    public:
        std::string m_name;

    public:
        bool m_dirty = false;
};