#ifndef HOTEL_HANDLER_HPP
#define HOTEL_HANDLER_HPP

#include "Hotel.hpp"

class Hotel_Handler {

public:

	Hotel_Handler(std::string path);
	void print();
	void print(int id);

private:

	std::vector<Hotel*> read_hotel_file(std::string path);
	std::vector<Hotel*> hotels;
};

#endif