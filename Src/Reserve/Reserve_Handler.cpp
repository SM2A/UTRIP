#include "Reserve_Handler.hpp"
#include "../Utility/Error.hpp"
#include "Reserve.hpp"
#include <iostream>

#define EMPTY 0

void Reserve_Handler::print(int count) {

	if(reserves.size()==EMPTY) throw Empty();
	for(int i = reserves.size()-1 ; count!=0 ; count--)
		reserves[i]->print();
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