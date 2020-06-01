#ifndef HOTEL_HANDLER_HPP
#define HOTEL_HANDLER_HPP

#include <string>
#include <vector>

class Hotel;

class Hotel_Handler {

public:

	Hotel_Handler(){}
	Hotel_Handler(std::string path);
	void print();
	void print(std::string id);
	Hotel* find(std::string id);
	friend class City;
	friend class Star_Range;
	friend class Average_Price;
	friend class Available_Room;

private:

	std::vector<Hotel*> read_hotel_file(std::string path);
	std::vector<Hotel*> hotels;
};

#endif