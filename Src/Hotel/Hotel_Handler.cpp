#include "Hotel_Handler.hpp"
#include <iostream>

using namespace std;

Hotel_Handler::Hotel_Handler(string path) {
	this->hotels = read_hotel_file(path);
}

vector<Hotel*> Hotel_Handler::read_hotel_file(string path) {

}