#ifndef UTRIP_HPP
#define UTRIP_HPP

#include "../Hotel/Hotel_Handler.hpp"
#include "../User/User_Handler.hpp"

class Utrip {

public:

	static Utrip* get_instance(){
		//todo WTFFFFFFFFFFFFFF
		//path = path_;
		if(!instance) instance = new Utrip();
		return instance;
	}

private:

	Utrip(){}
	static Utrip* instance;
	//static std::string path;
	Hotel_Handler* hotels;
	User_Handler* users;

};

#endif