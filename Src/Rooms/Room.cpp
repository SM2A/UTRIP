#include "Room.hpp"

bool Room::is_available(range request_date) {

	return !Date().have_interference(reserve_date_,request_date);
}

Room::Room(int id_) : id(id_) {

	this->reserve_date_.start.set_day(NOT_RESERVED);
	this->reserve_date_.end.set_day(NOT_RESERVED);
}
