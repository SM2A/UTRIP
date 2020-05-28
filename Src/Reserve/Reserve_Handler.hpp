#ifndef RESERVE_HANDLER_HPP
#define RESERVE_HANDLER_HPP

#include <vector>

class Reserve;

class Reserve_Handler {

public:

	Reserve_Handler(){}
	void print(int count);
	float cancel(int id);

	Reserve* find(int id);

private:

	std::vector<Reserve*> reserves;
};

#endif