#ifndef FILTER_HPP
#define FILTER_HPP

class Hotel_Handler;

class Filter {

	virtual Hotel_Handler* apply(Hotel_Handler* hotels) = 0;
};

#endif