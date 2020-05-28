#include "UTrip.hpp"

using namespace std;

UTrip::UTrip(string path) {

	hotels = new Hotel_Handler(path);
	users = new User_Handler();
	logged_in_user = nullptr;
}

void UTrip::cancel_reservation(int id) {

	logged_in_user->cancel_reservation(id);
}