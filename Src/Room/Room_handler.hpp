#ifndef ROOM_HANDLER_HPP
#define ROOM_HANDLER_HPP

#include <vector>
#include "Delux/Deluxe_Room.hpp"
#include "Luxury/Luxury_Room.hpp"
#include "Premium/Premium_Room.hpp"
#include "Standard/Standard_Room.hpp"

typedef std::pair<int,int> price_count;
struct rooms_data{
	price_count standard;
	price_count deluxe;
	price_count luxury;
	price_count premium;
};
typedef struct rooms_data room_data;

class Room_handler {

public:

	Room_handler(room_data data);

private:

	std::pair<int,std::vector<Standard_Room*>> standard;
	std::pair<int,std::vector<Deluxe_Room*>> deluxe;
	std::pair<int,std::vector<Luxury_Room*>> luxury;
	std::pair<int,std::vector<Premium_Room*>> premium;
	void creat_standard_room(price_count standard_);
	void creat_deluxe_room(price_count deluxe_);
	void creat_luxury_room(price_count luxury_);
	void creat_premium_room(price_count premium_);

};

#endif