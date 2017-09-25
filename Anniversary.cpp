//
// Created by Marc Reinecker on 9/20/17.
//

#include "Anniversary.h"

// constructor with year
Anniversary::Anniversary(int _year, int _month, int _day) : _year(_year), _month(_month), _day(_day) {}

// constructor without year, sets year to 0
Anniversary::Anniversary(int _month, int _day) : _month(_month), _day(_day) {
	_year = 0;
}

// default constructor initializes all values to 0
Anniversary::Anniversary() {
	_day = 0;
	_month = 0;
	_year = 0;
}

// destructor
Anniversary::~Anniversary() = default;

int Anniversary::get_year() const {
	return _year;
}

void Anniversary::set_year(int _year) {
	Anniversary::_year = _year;
}

int Anniversary::get_month() const {
	return _month;
}

void Anniversary::set_month(int _month) {
	Anniversary::_month = _month;
}

int Anniversary::get_day() const {
	return _day;
}

void Anniversary::set_day(int _day) {
	Anniversary::_day = _day;
}

// overloaded operators
bool Anniversary::operator<(const Anniversary &rhs) const {
	if (_year < rhs._year)
		return true;
	if (rhs._year < _year)
		return false;
	if (_month < rhs._month)
		return true;
	if (rhs._month < _month)
		return false;
	return _day < rhs._day;
}

bool Anniversary::operator>(const Anniversary &rhs) const {
	return rhs < *this;
}

bool Anniversary::operator<=(const Anniversary &rhs) const {
	return !(rhs < *this);
}

bool Anniversary::operator>=(const Anniversary &rhs) const {
	return !(*this < rhs);
}

// sends each data member out in readable format, omits year if set to 0
std::ostream &operator<<(std::ostream &os, const Anniversary &anniversary) {
	(anniversary._year != 0 ? os << "Year: " << anniversary._year : os) << " Month: " << anniversary._month << " Day: " << anniversary._day;
	return os;
}

// only compares month and day since some elements ignore year
bool Anniversary::operator==(const Anniversary &rhs) const {
	return std::tie(_month, _day) == std::tie(rhs._month, rhs._day);
}

bool Anniversary::operator!=(const Anniversary &rhs) const {
	return !(rhs == *this);
}
