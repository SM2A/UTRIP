#ifndef HOTEL_HPP
#define HOTEL_HPP

#include <string>
#include "../Room/Room_handler.hpp"

struct coordinates{
	double longitude;
	double latitude;
};
typedef struct coordinates geographical_coordinates;

class Hotel {

public:

	Hotel(std::string id_,std::string name_,int star_,std::string overview_,std::string facilities_,std::string city_,
			geographical_coordinates location_,std::string image_url_,room_data data);

private:

	std::string id;
	std::string name;
	int star;
	std::string overview;
	std::string facilities;
	std::string city;
	geographical_coordinates location;
	std::string image_url;
	Room_handler* rooms;
	int total_rooms_count;
	float average_price;

	float calculate_average_price(room_data data);

};

#endif