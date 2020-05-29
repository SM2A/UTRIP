#include "Hotel_Handler.hpp"
#include "../Utility/Error.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

#define COLUMN_DELIMITER ','
#define EMPTY 0

using namespace std;

Hotel_Handler::Hotel_Handler(string path) {
	this->hotels = read_hotel_file(path);
}

vector<Hotel*> Hotel_Handler::read_hotel_file(string path) {

	vector<Hotel*> hotels_;

	ifstream file(path);
	string first_row , row;
	getline(file,first_row);

	while (getline(file,row)){
		stringstream stream(row);
		string id,name,overview,facilities,city,image_url,star,longitude,latitude,rooms_data;
		geographical_coordinates geo_coordinates;
		room_data rooms;
		getline(stream,id,COLUMN_DELIMITER);
		getline(stream,name,COLUMN_DELIMITER);
		getline(stream,star,COLUMN_DELIMITER);
		getline(stream,overview,COLUMN_DELIMITER);
		getline(stream,facilities,COLUMN_DELIMITER);
		getline(stream,city,COLUMN_DELIMITER);
		getline(stream,latitude,COLUMN_DELIMITER);
		getline(stream,longitude,COLUMN_DELIMITER);
		getline(stream,image_url,COLUMN_DELIMITER);
		geo_coordinates.latitude = stod(latitude);
		geo_coordinates.longitude = stod(longitude);
		getline(stream,rooms_data,COLUMN_DELIMITER);
		rooms.standard.second = stoi(rooms_data);
		getline(stream,rooms_data,COLUMN_DELIMITER);
		rooms.deluxe.second = stoi(rooms_data);
		getline(stream,rooms_data,COLUMN_DELIMITER);
		rooms.luxury.second = stoi(rooms_data);
		getline(stream,rooms_data,COLUMN_DELIMITER);
		rooms.premium.second = stoi(rooms_data);
		getline(stream,rooms_data,COLUMN_DELIMITER);
		rooms.standard.first = stoi(rooms_data);
		getline(stream,rooms_data,COLUMN_DELIMITER);
		rooms.deluxe.first = stoi(rooms_data);
		getline(stream,rooms_data,COLUMN_DELIMITER);
		rooms.luxury.first = stoi(rooms_data);
		getline(stream,rooms_data,COLUMN_DELIMITER);
		rooms.premium.first = stoi(rooms_data);
		Hotel* _hotel = new Hotel(id,name,stoi(star),overview,facilities,city,geo_coordinates,image_url,rooms);
		hotels_.push_back(_hotel);
	}
	sort(hotels_.begin(),hotels_.end(),sort_by_name);
	return hotels_;
}

void Hotel_Handler::print() {

	if(hotels.size() == EMPTY) throw Empty();
	for(Hotel* hotel : hotels)
		hotel->print_summary();
}