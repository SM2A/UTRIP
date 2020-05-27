#ifndef USER_HPP
#define USER_HPP

#include <string>
#include <vector>
#include "../Reserve/Reserve_Handler.hpp"

class User {

public:

private:

	std::string name;
	std::string password;
	std::string email;
	float credit;
	std::vector<float> credit_report;
	Reserve_Handler* reservations;
};

#endif