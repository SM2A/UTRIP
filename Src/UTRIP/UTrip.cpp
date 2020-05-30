#include "UTrip.hpp"
#include <iostream>
#include "../Hotel/Hotel.hpp"
#include "../Utility/Error.hpp"

#define SUCCESS "OK"

using namespace std;

UTrip::UTrip(string path) {

	hotels = new Hotel_Handler(path);
	users = new User_Handler();
	logged_in_user = nullptr;
}

void UTrip::cancel_reservation(int id) {

	if(!is_user_logged_in()) throw Permission_Denied();
	logged_in_user->cancel_reservation(id);
}

void UTrip::creat_user(string user_name, string password, string e_mail) {

	if(is_user_logged_in()) throw Permission_Denied();
	try {
		logged_in_user = users->creat_user(user_name, password, e_mail);
		cout<<SUCCESS<<endl;
	}catch (exception& e){
		cout<<e.what()<<endl;
		delete(logged_in_user);
		logged_in_user = nullptr;
	}
}

void UTrip::logout() {

	if(!is_user_logged_in()) throw Permission_Denied();
	logged_in_user = nullptr;
	cout<<SUCCESS<<endl;
}

void UTrip::login(string user_name, string password) {

	if(is_user_logged_in()) throw Permission_Denied();
	try {
		cout<<SUCCESS<<endl;
		logged_in_user = users->login(user_name,password);
	}catch (exception& e){
		cout<<e.what()<<endl;
		logged_in_user = nullptr;
	}
}

void UTrip::add_credit(float value) {

	if(!is_user_logged_in()) throw Permission_Denied();
	logged_in_user->add_credit(value);
}

bool UTrip::is_user_logged_in() {

	return logged_in_user != nullptr;
}

void UTrip::wallet_history(int count) {

	if(!is_user_logged_in()) throw Permission_Denied();
	logged_in_user->print_wallet_history(count);
}

void UTrip::show_hotel() {

	if(!is_user_logged_in()) throw Permission_Denied();
	try {
		hotels->print();
	}catch (exception& e){
		cout<<e.what()<<endl;
	}
}

void UTrip::show_hotel(string id) {

	if(!is_user_logged_in()) throw Permission_Denied();
	try {
		hotels->print(id);
	}catch (exception& e){
		cout<<e.what()<<endl;
	}
}

void UTrip::reserve(string hotel_id, string room_type, int quantity, int check_in, int check_out) {

	if(!is_user_logged_in()) throw Permission_Denied();
	range reserve_date;
	reserve_date.start.set_day(check_in);
	reserve_date.end.set_day(check_out);
	try {
		Hotel *hotel = hotels->find(hotel_id);
		if(!logged_in_user->have_enough_credit(hotel->reserve_cost(room_type,quantity,reserve_date)))
			throw Not_Enough_Credit();
		logged_in_user->reserve(hotel,room_type,quantity,
				reserve_date,hotel->reserve_cost(room_type,quantity,reserve_date));
	}catch (exception& e){
		cout<<e.what()<<endl;
	}
}