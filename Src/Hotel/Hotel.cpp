#include "Hotel.hpp"
#include <iostream>
#include <iomanip>

#define EMPTY 0
#define EXPONENT 2

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
	int type_count = 0;
	long total_price = 0;

	if(data.standard.second!=EMPTY){
		type_count++;
		total_price+=data.standard.first;
	}
	if(data.deluxe.second!=EMPTY){
		type_count++;
		total_price+=data.deluxe.first;
	}
	if(data.luxury.second!=EMPTY){
		type_count++;
		total_price+=data.luxury.first;
	}
	if(data.premium.second!=EMPTY){
		type_count++;
		total_price+=data.premium.first;
	}

	if(type_count==EMPTY) avg_price=EMPTY;
	else avg_price = (float) total_price/(float)type_count;
	return avg_price;
}

void Hotel::print_summary() {

	string summary = id +" "+ name +" "+ to_string(star) +" "+ city +" "+ to_string(total_rooms_count)+" ";
	cout<<summary<<fixed<<setprecision(EXPONENT)<<average_price<<endl;
}

bool sort_by_name(Hotel* one , Hotel* two){ return two->id > one->id;}