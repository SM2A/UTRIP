#ifndef UTRIP_HPP
#define UTRIP_HPP

#include "../Hotel/Hotel_Handler.hpp"
#include "../User/User_Handler.hpp"

class UTrip {

public:

	UTrip(std::string path);
	void cancel_reservation(int id);

private:

	Hotel_Handler* hotels;
	User_Handler* users;

	User* logged_in_user;
};

#endif