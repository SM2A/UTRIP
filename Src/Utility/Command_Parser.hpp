#ifndef COMMAND_PARSER_HPP
#define COMMAND_PARSER_HPP

#include <string>
#include "../UTRIP/UTrip.hpp"

class Command_Parser {

public:

	Command_Parser(std::string path);
	void get_command(std::string command);

private:

	UTrip* utrip;
	const std::string method[2] = {"GET","POST"};

	void signup();
	void login();
	void logout();
	void add_credit();
	void show_wallet_history();
	void show_hotels();
	void show_hotel_detail();
	//todo filter
	//tod delete filter
	void reserve();
	void show_reserves();
	void cancel_reserve();
	void show_hotel_ratting();
	void show_hotel_comments();
	void add_comment();
	void add_ratting();

	void method_check(std::string method_);
};

#endif