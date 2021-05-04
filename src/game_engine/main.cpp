#include <iostream>
#include "game_engine.h"
#include "engine_config.h"
#include "player.h"

#include <thread>
#include <mysql_connection.h>
#include <mysql_driver.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>

void hello() {
	std::cout << "hello" << std::endl;
}

int main(int argc, char* argv[]) {
	auto node = common::get_yaml_config("engine_config.yml");
	// std::cout << "game_engine ip: " << node["game_engine"]["ip"] << std::endl;
	// std::cout << "game_engine port: " << node["game_engine"]["port"] << std::endl;

	GameEngine ge;
	ge.init();
	ge.run();

	// 线程
	// std::thread t(hello);
	// std::cout << "thread hardware connconrency " << t.hardware_concurrency() << std::endl;
	// t.join();

	// sql::mysql::MySQL_Driver *driver;
	// sql::Connection *conn;
	// sql::Statement *state;
	// sql::ResultSet *result;
	// driver = sql::mysql::get_driver_instance();
	// conn = driver->connect("localhost", "dev", "123456");
	// state = conn->createStatement();
	// state->execute("use test");
	// result = state->executeQuery("select * from users");
	// // 输出查询
	// while (result->next())
	// {
	// 	std::cout << result->getString("id") << "	";
	// 	std::cout << result->getString("fullname") << std::endl;
	// }
	return 0;
}