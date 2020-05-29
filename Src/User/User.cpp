#include "User.hpp"
#include "../Utility/Error.hpp"
#include <iostream>
#include <iomanip>
#include <cmath>

#define INIT_CREDIT 0
#define EXPONENT 2
#define SUCCESS "OK"

using namespace std;

User::User(string user_name, string password_, string e_mail) {

	name = user_name;
	password = hash<string>{}(password_);
	email = e_mail;
	credit = INIT_CREDIT;
	reservations = new Reserve_Handler();
	credit_report.push_back(credit);
}

void User::identity_taken_check(User *new_user, User *user) {

	if(new_user->name == user->name) throw Bad_Request();
	if(new_user->email == user->email) throw Bad_Request();
}

void User::cancel_reservation(int id) {

	float cost = reservations->cancel(id);
	credit+=cost;
}

void User::is_credentials_valid(string password_) {
	size_t pass = hash<string>{}(password_);
	if(pass!=password) throw Bad_Request();
}

void User::add_credit(float value) {

	if(value <= INIT_CREDIT) throw Bad_Request();
	credit+=value;
	credit_report.push_back(credit);
	cout<<SUCCESS<<endl;
}

void User::print_wallet_history(int count) {

	for (int i = 0; (i < credit_report.size()) && (i != count); i++) {
		if (credit_report[(credit_report.size()-1)-i] == floor(credit_report[(credit_report.size()-1)-i]) ) {
			cout << credit_report[(credit_report.size() - 1) - i] << endl;
		} else {
			cout << fixed;
			cout << setprecision(EXPONENT) << credit_report[(credit_report.size() - 1) - i] << endl;
		}
	}
}