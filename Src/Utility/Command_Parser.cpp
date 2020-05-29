#include "Command_Parser.hpp"
#include "Error.hpp"
#include <sstream>

#define ID "id"
#define USER_NAME "username"
#define E_MAIL "email"
#define PASSWORD "password"

using namespace std;

Command_Parser::Command_Parser(string path) {

	utrip = new UTrip(path);
}

void Command_Parser::method_check(string method_) {

	for(const string& m : method)
		if(m==method_) return;
	throw Bad_Request();
}

void Command_Parser::cancel_reserve(arguments args) {

	utrip->cancel_reservation(stoi(find_arg_val(args,ID)));
}

void Command_Parser::get_command(string command) {

	stringstream stream(command);
	string method_ , command_ , question_mark;
	stream>>method_>>command_>>question_mark;
	method_check(method_);
	arguments arguments_;
	string arg , val;
	while (stream>>arg>>val) arguments_.insert(argument_value(arg,val));

}

string Command_Parser::find_arg_val(const arguments& args,string arg) {

	for(argument_value av : args)
		if(av.first==arg) return av.second;
	throw Bad_Request();
}

void Command_Parser::signup(arguments args) {

	utrip->creat_user(find_arg_val(args,USER_NAME),find_arg_val(args,PASSWORD),find_arg_val(args,E_MAIL));
}

void Command_Parser::logout() {

	utrip->logout();
}