//
// Created by Marc Reinecker on 9/20/17.
//

#ifndef FINAL_1_ANNIVERSARY_H
#define FINAL_1_ANNIVERSARY_H

#include <iostream>
using namespace std;

class Anniversary {
	// store month day and year
		int _year;
		int _month;
		int _day;
public:
	// default constructor
	Anniversary();
	// constructor with arguments
	Anniversary(int _year, int _month, int _day);
	// constructor to exclude year
	Anniversary(int _month, int _day);
	// destructor
	virtual ~Anniversary();
	// getters and setters
	int get_year() const;

	void set_year(int _year);

	int get_month() const;

	void set_month(int _month);

	int get_day() const;

	void set_day(int _day);
	// overloaded operators
	bool operator<(const Anniversary &rhs) const;

	bool operator>(const Anniversary &rhs) const;

	bool operator<=(const Anniversary &rhs) const;

	bool operator>=(const Anniversary &rhs) const;

	bool operator==(const Anniversary &rhs) const;

	bool operator!=(const Anniversary &rhs) const;

	friend std::ostream &operator<<(std::ostream &os, const Anniversary &anniversary);
};


#endif //FINAL_1_ANNIVERSARY_H
