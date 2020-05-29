#ifndef RESERVE_HPP
#define RESERVE_HPP

#include <string>
#include "Reserve_Handler.hpp"

class Reserve {

public:

	Reserve(std::string hotel_id , std::string room_type , int quantity , int cost , int check_in ,
			int check_out , bool cancelled = false);

	void print();
	float cancel();

private:

	int id;
	std::string hotel_id;
	std::string room_type;
	int quantity;
	int cost;
	int check_in;
	int check_out;
	bool cancelled;

	friend Reserve* Reserve_Handler::find(int id);
};

#endif