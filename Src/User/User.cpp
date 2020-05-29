#include "User.hpp"
#include "../Utility/Error.hpp"

#define INIT_CREDIT 0

using namespace std;

User::User(string user_name, string password_, string e_mail) {

	name = user_name;
	password = hash<string>{}(password_);
	email = e_mail;
	credit = INIT_CREDIT;
	reservations = new Reserve_Handler();
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
}