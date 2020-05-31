#include "Command_Parser.hpp"
#include "Error.hpp"
#include <sstream>
#include <iostream>

#define ID "id"
#define USER_NAME "username"
#define E_MAIL "email"
#define PASSWORD "password"
#define AMOUNT "amount"
#define COUNT "count"
#define HOTEL "hotel"
#define  TYPE "type"
#define QUANTITY "quantity"
#define CHECK_IN "check_in"
#define CHECK_OUT "check_out"
#define COMMENT "comment"

using namespace std;

Command_Parser::Command_Parser(string path) {

	utrip = new UTrip(path);
}

void Command_Parser::method_check(string method_) {

	for(const string& m : method)
		if(m==method_) return;
	throw Bad_Request();
}

void Command_Parser::get_command(string command) {

	stringstream stream(command);
	string method_ , command_ , question_mark;
	stream>>method_>>command_>>question_mark;
	method_check(method_);
	arguments arguments_;
	string arg , val;
	while (stream>>arg>>val) arguments_.insert(argument_value(arg,val));

	try {
		if (method_ == method[GET]) get_parser(command_, arguments_);
		else if (method_ == method[POST]) post_parser(command_, arguments_);
		else if (method_ == method[DELETE]) delete_parser(command_, arguments_);
	}catch (exception& e){
		cout<<e.what()<<endl;
	}
}

string Command_Parser::find_arg_val(const arguments& args,string arg) {

	for(argument_value av : args)
		if(av.first==arg) return av.second;
	throw Bad_Request();
}

void Command_Parser::signup(const arguments& args) {

	utrip->creat_user(find_arg_val(args,USER_NAME),find_arg_val(args,PASSWORD),find_arg_val(args,E_MAIL));
}

void Command_Parser::logout(const arguments &args) {

	if(args.size()!=0) throw Bad_Request();
	utrip->logout();
}

void Command_Parser::login(const arguments &args) {

	utrip->login(find_arg_val(args,USER_NAME),find_arg_val(args,PASSWORD));
}

void Command_Parser::get_parser(string command_, const arguments &args) {

	if(command_== "wallet") show_wallet_history(args);
	else if(command_== "hotels") show_hotels(args);
	else if(command_== "reserves") show_reserves(args);
	else if(command_== "comments") show_hotel_comments(args);
	else if(command_== "ratings");
	else throw Bad_Request();
}

void Command_Parser::post_parser(string command_, const arguments &args) {

	if(command_== "signup") signup(args);
	else if(command_== "login") login(args);
	else if(command_== "logout") logout(args);
	else if(command_== "wallet") add_credit(args);
	else if(command_== "filters");
	else if(command_== "reserves") reserve(args);
	else if(command_== "comments") add_comment(args);
	else if(command_== "ratings");
	else throw Bad_Request();
}

void Command_Parser::delete_parser(string command_, const arguments &args) {

	if(command_== "filters");
	else if(command_== "reserves")cancel_reserve(args);
	else throw Bad_Request();
}

void Command_Parser::add_credit(const arguments &args) {

	utrip->add_credit(stof(find_arg_val(args,AMOUNT)));
}

void Command_Parser::show_wallet_history(const arguments &args) {

	utrip->wallet_history(stoi(find_arg_val(args,COUNT)));
}

void Command_Parser::show_hotels(const arguments &args) {

	if(args.size() == 0) utrip->show_hotel();
	else utrip->show_hotel(find_arg_val(args,ID));
}

void Command_Parser::reserve(const arguments &args) {

	utrip->reserve(find_arg_val(args,HOTEL),find_arg_val(args,TYPE),stoi(find_arg_val(args,QUANTITY)),
	               stoi(find_arg_val(args,CHECK_IN)),stoi(find_arg_val(args,CHECK_OUT)));
}

void Command_Parser::show_reserves(const arguments &args) {

	if(args.size()!=0) throw Bad_Request();
	utrip->show_reserves();
}

void Command_Parser::cancel_reserve(const arguments &args) {

	utrip->cancel_reservation(stoi(find_arg_val(args,ID)));
}

void Command_Parser::add_comment(const arguments &args) {

	utrip->add_comment(find_arg_val(args,HOTEL),find_arg_val(args,COMMENT));
}

void Command_Parser::show_hotel_comments(const arguments &args) {

	utrip->show_hotel_comment(find_arg_val(args,HOTEL));
}