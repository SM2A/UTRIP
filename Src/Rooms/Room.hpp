#ifndef A7_ROOM_HPP
#define A7_ROOM_HPP

#include "../Utility/Date.hpp"

class Room {

public:

    Room(int id);

private:

    int id;
    bool is_empty;
	struct reserve_date{
		Date start;
		Date end;
	}reserve_date_;

};

#endif