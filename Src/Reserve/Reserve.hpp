#ifndef RESERVE_HPP
#define RESERVE_HPP

#include <string>

class Reserve {

public:

	Reserve(std::string hotel_id , std::string room_type , int quantity , int check_in ,
			int check_out , bool cancelled = false);

private:

	int id;
	std::string hotel_id;
	std::string room_type;
	int quantity;
	int check_in;
	int check_out;
	bool cancelled;
};

#endif