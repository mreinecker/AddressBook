//
// Created by Marc Reinecker on 9/20/17.
//

#include "Birthday.h"

// default constructor initializes members to 0
Birthday::Birthday() {
	_day = 0;
	_month = 0;
	_year = 0;
}
// constructor
Birthday::Birthday(int _year, int _month, int _day) : _year(_year), _month(_month), _day(_day) {}
// constructor that doesn't take year, initializes year to 0
Birthday::Birthday(int _month, int _day) : _month(_month), _day(_day) {
	_year = 0;
}
// destructor
Birthday::~Birthday() = default;
// getters and setters
int Birthday::get_year() const {
	return _year;
}

void Birthday::set_year(int _year) {
	Birthday::_year = _year;
}

int Birthday::get_month() const {
	return _month;
}

void Birthday::set_month(int _month) {
	Birthday::_month = _month;
}

int Birthday::get_day() const {
	return _day;
}

void Birthday::set_day(int _day) {
	Birthday::_day = _day;
}
// overloaded << operator omits year if set to 0
ostream &operator<<(ostream &os, const Birthday &birthday) {
	(birthday._year != 0 ? os << "Year: " << birthday._year : os) << " Month: " << birthday._month << " Day: " << birthday._day;
	return os;
}
// comparison just compares month and day since some elements ignore year
bool Birthday::operator==(const Birthday &rhs) const {
	return std::tie(_month, _day) == std::tie(rhs._month, rhs._day);
}

bool Birthday::operator!=(const Birthday &rhs) const {
	return !(rhs == *this);
}

