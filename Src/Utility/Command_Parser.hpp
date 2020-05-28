#ifndef COMMAND_PARSER_HPP
#define COMMAND_PARSER_HPP

#include <string>
#include "../UTRIP/UTrip.hpp"

class Command_Parser {

public:

	Command_Parser(std::string path);

private:

	UTrip* utrip;

};

#endif