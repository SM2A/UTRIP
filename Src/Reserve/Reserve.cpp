#include "Reserve.hpp"

using namespace std;

Reserve::Reserve(string hotel_id,string room_type, int quantity, int check_in, int check_out,bool cancelled) {

	this->hotel_id = hotel_id;
	this->room_type = room_type;
	this->quantity = quantity;
	this->check_in = check_in;
	this->check_out = check_out;
	this->cancelled = cancelled;
}