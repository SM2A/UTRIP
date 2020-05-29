#ifndef USER_HANDLER_HPP
#define USER_HANDLER_HPP

#include "User.hpp"

class User_Handler {

public:

	User_Handler(){}
	User* creat_user(std::string user_name , std::string password , std::string e_mail);

private:

	std::vector<User*> users;
};

#endif