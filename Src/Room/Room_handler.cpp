#include "Room_handler.hpp"

using namespace std;

Room_handler::Room_handler(room_data data) {

	creat_standard_room(data.standard);
	creat_deluxe_room(data.deluxe);
	creat_luxury_room(data.luxury);
	creat_premium_room(data.premium);
}

void Room_handler::creat_standard_room(price_count standard_) {

	this->standard.first = standard_.first;
	for (int i = 0; i < standard_.second ; ++i) {
		Standard_Room* room = new Standard_Room(i+1);
		this->standard.second.push_back(room);
	}
}

void Room_handler::creat_deluxe_room(price_count deluxe_) {

	this->deluxe.first = deluxe_.first;
	for (int i = 0; i < deluxe_.second ; ++i) {
		Deluxe_Room* room = new Deluxe_Room(i+1);
		this->deluxe.second.push_back(room);
	}
}

void Room_handler::creat_luxury_room(price_count luxury_) {

	this->luxury.first = luxury_.first;
	for (int i = 0; i < luxury_.second ; ++i) {
		Luxury_Room* room = new Luxury_Room(i+1);
		this->luxury.second.push_back(room);
	}
}

void Room_handler::creat_premium_room(price_count premium_) {

	this->premium.first = premium_.first;
	for (int i = 0; i < premium_.second ; ++i) {
		Premium_Room* room = new Premium_Room(i+1);
		this->premium.second.push_back(room);
	}
}

std::string Room_handler::rooms_count() {

	string out = to_string(standard.second.size()) +" "+ to_string(deluxe.second.size()) +" "+
			to_string(luxury.second.size()) +" "+ to_string(premium.second.size());
	return out;
}

std::string Room_handler::rooms_price() {

	string out = to_string(standard.first) +" "+ to_string(deluxe.first) +" "+to_string(luxury.first) +" "+
			to_string(premium.first);
	return out;
}
