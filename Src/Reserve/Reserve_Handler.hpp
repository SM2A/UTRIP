#ifndef RESERVE_HANDLER_HPP
#define RESERVE_HANDLER_HPP

#include <vector>
#include "Reserve.hpp"

class Reserve_Handler {

public:

	Reserve_Handler(){}
	void print();
	void cancel(int id);

private:

	std::vector<Reserve*> reserves;

};

#endif