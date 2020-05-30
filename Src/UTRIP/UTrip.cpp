#include "UTrip.hpp"
#include <iostream>
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

void UTrip::show_hotel(std::string id) {

	if(!is_user_logged_in()) throw Permission_Denied();
	try {
		hotels->print(id);
	}catch (exception& e){
		cout<<e.what()<<endl;
	}
}