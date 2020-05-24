#include "Room.hpp"

bool Room::is_available(range request_date) {

	return !Date().have_interference(reserve_date_,request_date);
}
