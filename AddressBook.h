//
// Created by Marc Reinecker on 9/19/17.
//

#ifndef FINAL_1_ADDRESSBOOK_H
#define FINAL_1_ADDRESSBOOK_H

#include <iostream>
#include <utility>
#include <list>
#include "Birthday.h"
#include "Anniversary.h"

using namespace std;





class AddressBook {
	string _name; // store name
	const string _address; // store address
	Birthday _birthday; // store birthday type
	Anniversary _anniversary; // store anniversary type
public:
	AddressBook() = default; // default constructor

	// constructor to take arguments
	AddressBook(const string &_name, const string &_address, const Birthday &_birthday,
	            const Anniversary &_anniversary);

	// destructor
	virtual ~AddressBook();

	// getters and setters
	void set_name(string new_name);

	const Birthday &get_birthday() const;

	void set_birthday(const Birthday &_birthday);

	const Anniversary &get_anniversary() const;

	void set_anniversary(const Anniversary &_anniversary);

	const string &getName() const;

	//overloaded operators
	bool operator<(const AddressBook &rhs) const;

	bool operator>(const AddressBook &rhs) const;

	bool operator<=(const AddressBook &rhs) const;

	bool operator>=(const AddressBook &rhs) const;

	bool operator==(const AddressBook &rhs) const;

	bool operator!=(const AddressBook &rhs) const;

	friend ostream &operator<<(ostream &os, const AddressBook &book);

};




#endif //FINAL_1_ADDRESSBOOK_H
