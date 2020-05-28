#include "Command_Parser.hpp"
#include "Error.hpp"

using namespace std;

Command_Parser::Command_Parser(std::string path) {

	utrip = new UTrip(path);
}

void Command_Parser::method_check(string method_) {

	for(const string& m : method)
		if(m==method_) return;
	throw Bad_Request();
}