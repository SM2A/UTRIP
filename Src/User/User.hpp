#ifndef USER_HPP
#define USER_HPP

#include <string>
#include <vector>
#include "../Reserve/Reserve_Handler.hpp"
#include "User_Handler.hpp"

class User {

public:

	User(std::string user_name , std::string password_ , std::string e_mail);
	void identity_taken_check(User* new_user , User* user);
	void cancel_reservation(int id);
	void is_credentials_valid(std::string password);
	void add_credit(float value);

private:

	std::string name;
	size_t password;
	std::string email;
	float credit;
	std::vector<float> credit_report;
	Reserve_Handler* reservations;

	friend User* User_Handler::find(std::string user_name);
};

#endif