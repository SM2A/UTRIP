#ifndef A7_ROOM_HPP
#define A7_ROOM_HPP

#include "../Utility/Date.hpp"

#define NOT_RESERVED -1

class Room {

public:

    Room(int id_);
    bool is_available(range request_date);

private:

    int id;
	range reserve_date_;
};

#endif