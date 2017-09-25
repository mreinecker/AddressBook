//
// Created by Marc Reinecker on 9/19/17.
//

#include "AddressBook.h"


using namespace std;

// function to lowercase a string used in relational operator overload
char toLower(string msg) {
	std::locale loc;
	std::string str = std::move(msg);
	for (char i : str)
		return std::tolower(i, loc);
}

// constructor
AddressBook::AddressBook(const string &_name, const string &_address, const Birthday &_birthday,
                         const Anniversary &_anniversary) : _name(_name), _address(_address), _birthday(_birthday),
                                                            _anniversary(_anniversary) {}

// destructor
AddressBook::~AddressBook() = default;

const string &AddressBook::getName() const {
	return _name;
}

// overloaded to allow type to be used with << operator to send data members out in readable format
ostream &operator<<(ostream &os, const AddressBook &book) {
	os << "Name: " << book._name << " Address: " << book._address << " Birthday: " << book._birthday
	   << " Anniversary: " << book._anniversary;
	return os;
}


const Birthday &AddressBook::get_birthday() const {
	return _birthday;
}

void AddressBook::set_birthday(const Birthday &_birthday) {
	AddressBook::_birthday = _birthday;
}

const Anniversary &AddressBook::get_anniversary() const {
	return _anniversary;
}

void AddressBook::set_anniversary(const Anniversary &_anniversary) {
	AddressBook::_anniversary = _anniversary;
}


void AddressBook::set_name(const string new_name) {
	AddressBook::_name = new_name;
}

// allows .sort on list to sort by names, not affected by case
bool AddressBook::operator<(const AddressBook &rhs) const {
	return toLower(_name) < toLower(rhs._name);
}

bool AddressBook::operator>(const AddressBook &rhs) const {
	return rhs < *this;
}

bool AddressBook::operator<=(const AddressBook &rhs) const {
	return !(rhs < *this);
}

bool AddressBook::operator>=(const AddressBook &rhs) const {
	return !(*this < rhs);
}

bool AddressBook::operator==(const AddressBook &rhs) const {

}

bool AddressBook::operator!=(const AddressBook &rhs) const {
	return !(rhs == *this);
}













