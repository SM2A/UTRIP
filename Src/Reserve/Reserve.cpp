#include "Reserve.hpp"
#include <iostream>
#include "../Utility/Error.hpp"

using namespace std;

Reserve::Reserve(string hotel_id,string room_type, int quantity, int cost , int check_in, int check_out,bool cancelled) {

	this->hotel_id = hotel_id;
	this->room_type = room_type;
	this->quantity = quantity;
	this->cost = cost;
	this->check_in = check_in;
	this->check_out = check_out;
	this->cancelled = cancelled;
}

void Reserve::print() {

	if(cancelled) return;
	string output = "id:"+to_string(id)+" hotel:"+hotel_id+" room:"+room_type+" quantity: "+to_string(quantity)
			+" cost: "+to_string(cost)+" check_in: "+to_string(check_in)+" check_out: "+to_string(check_out);
	cout<<output<<endl;
}

float Reserve::cancel() {

	if(cancelled) throw Not_Found();
	cancelled = true;
	return cost;
}