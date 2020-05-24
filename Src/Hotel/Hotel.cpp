#include "Hotel.hpp"

#define EMPTY 0

using namespace std;

Hotel::Hotel(string id_, string name_, int star_, string overview_, string facilities_,string city_,
		geographical_coordinates location_, string image_url_, room_data data) {

	this->id = id_;
	this->name = name_;
	this->star = star_;
	this->overview = overview_;
	this->facilities = facilities_;
	this->city = city_;
	this->location = location_;
	this->image_url = image_url_;
	this->rooms = new Room_handler(data);
	this->total_rooms_count = data.standard.second + data.deluxe.second + data.luxury.second + data.premium.second;
	this->average_price = calculate_average_price(data);
}

float Hotel::calculate_average_price(room_data data) {

	float avg_price = 0;
	int rooms_count = data.standard.second + data.deluxe.second + data.luxury.second + data.premium.second;
	avg_price = data.standard.first + data.deluxe.first + data.luxury.first + data.premium.first;
	if(rooms_count==EMPTY) avg_price=EMPTY;
	else avg_price = (float)(avg_price/rooms_count);
	return avg_price;
}
