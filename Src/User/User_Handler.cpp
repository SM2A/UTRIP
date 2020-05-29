#include "User_Handler.hpp"
#include <iostream>
#include "User.hpp"

using namespace std;

User *User_Handler::creat_user(string user_name, string password, string e_mail) {

	User* new_user;
	try{
		new_user = new User(user_name,password,e_mail);
		for(User * user_ : users) user_->identity_taken_check(new_user,user_);
		users.push_back(new_user);
	}catch (exception& e){
		cout<<e.what()<<endl;
		delete(new_user);
	}
	return new_user;
}

User *User_Handler::find(string user_name) {

	for(User* u : users) if(u->name == user_name) return u;
	return nullptr;
}

User* User_Handler::login(string user_name , string password ) {

	User* user = find(user_name);
	user->is_credentials_valid(password);
	return user;
}