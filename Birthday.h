//
// Created by Marc Reinecker on 9/20/17.
//

#ifndef FINAL_1_BIRTHDAY_H
#define FINAL_1_BIRTHDAY_H

#include <iostream>
using namespace std;

class Birthday {
	// data members store year month day
	int _year;
	int _month;
	int _day;
public:
	// default constructor
	Birthday();
	// constructor
	Birthday(int _year, int _month, int _day);
	// constructor if year ignored
	Birthday(int _month, int _day);
	// destructor
	virtual ~Birthday();
	// getters and setters
	int get_year() const;

	void set_year(int _year);

	int get_month() const;

	void set_month(int _month);

	int get_day() const;

	void set_day(int _day);
	// overloaded operators
	bool operator==(const Birthday &rhs) const;

	bool operator!=(const Birthday &rhs) const;

	friend ostream &operator<<(ostream &os, const Birthday &birthday);
};


#endif //FINAL_1_BIRTHDAY_H
