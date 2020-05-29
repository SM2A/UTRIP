#ifndef UTRIP_HPP
#define UTRIP_HPP

#include "../Hotel/Hotel_Handler.hpp"
#include "../User/User_Handler.hpp"
#include "../User/User.hpp"

class UTrip {

public:

	UTrip(std::string path);
	void cancel_reservation(int id);
	void creat_user(std::string user_name , std::string password , std::string e_mail);
	void logout();
	void login(std::string user_name , std::string password);

private:

	Hotel_Handler* hotels;
	User_Handler* users;
	User* logged_in_user;
};

#endif