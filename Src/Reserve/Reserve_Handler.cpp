#include <iostream>
#include "Reserve_Handler.hpp"
#include "../Utility/Error.hpp"
#include "Reserve.hpp"

using namespace std;

#define EMPTY 0

void Reserve_Handler::print(int count) {

	if(reserves.size()==EMPTY) throw Empty();
	for(int i = 0 ; (i<reserves.size())&&(i!=count) ; i++)
		reserves[(reserves.size())-i]->print();
}

float Reserve_Handler::cancel(int id) {

	try {
		float cost = find(id)->cancel();
		return cost;
	}catch (...){
		throw Not_Found();
	}
}

Reserve *Reserve_Handler::find(int id) {

	for(Reserve* reserve : reserves)
		if(reserve->id == id) return reserve;

	//throw Not_Found();
	return nullptr;
}

void Reserve_Handler::reserve(string hotel_id,string room_type, int quantity, int cost, range reservation_date_,
		vector<Room *> rooms) {

	Reserve* reserve = new Reserve(hotel_id,room_type,quantity,cost,reservation_date_,rooms);
	for(Room* room : rooms) cout<<room->get_id()<<" ";
	cout<<endl;
	reserves.push_back(reserve);
}