#include <iostream>
#include "Hotel/Hotel_Handler.hpp"

using namespace std;

int main(int argc , char*argv[]) {

	Hotel_Handler* h = new Hotel_Handler(argv[1]);

    return 0;
}