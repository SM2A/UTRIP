#include "Date.hpp"

bool Date::have_interference(range first, range second) {

	if ((first.start.day == second.start.day) || (first.end.day == second.end.day)) return true;
	else if ((first.start.day > second.start.day) || (first.end.day < second.end.day)) return true;
	else if ((first.start.day < second.start.day) || (first.end.day > second.end.day)) return true;
	else if ((first.start.day < second.start.day) || (first.end.day < second.end.day)) return true;
	else if ((first.start.day > second.start.day) || (first.end.day > second.end.day)) return true;
	else return false;
}
