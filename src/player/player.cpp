#include <player.h>

Player::Player() {
}

Player::~Player() {
}

void Player::set_name(std::string name) {
    for (auto &ch: name) {
        m_name += std::toupper(ch);
    }

    return;
}

std::string Player::get_name() {
    return m_name;
}