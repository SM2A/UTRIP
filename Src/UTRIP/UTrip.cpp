#include "UTrip.hpp"
#include <iostream>

#define SUCCESS "OK"

using namespace std;

UTrip::UTrip(string path) {

	hotels = new Hotel_Handler(path);
	users = new User_Handler();
	logged_in_user = nullptr;
}

void UTrip::cancel_reservation(int id) {

	logged_in_user->cancel_reservation(id);
}

void UTrip::creat_user(string user_name, string password, string e_mail) {

	try {
		logged_in_user = users->creat_user(user_name, password, e_mail);
	}catch (exception& e){
		cout<<e.what()<<endl;
		delete(logged_in_user);
		logged_in_user = nullptr;
	}
}

void UTrip::logout() {

	logged_in_user = nullptr;
	cout<<SUCCESS<<endl;
}