#include <iostream>
#include <player.h>

int main(int argc, char* argv[]) {
	Player player;
	player.set_name("Hello World!");
	std::cout << "player's name: " << player.get_name() << std::endl;
	return 0;
}
