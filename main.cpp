#include <iostream>
#include <list> // to use built in linked list
#include "AddressBook.h"
#include <fstream>


using namespace std;


class HasIdentifier { // to identify name in each element when searching for iterator
public:
	explicit HasIdentifier(std::string id) :
			m_id(std::move(id)) 	{}

	bool operator()(AddressBook const& c)const
	{
		return (c.getName() == m_id);
	}
private:
	std::string m_id;
};




int main(){

	list<AddressBook> name_list; // linked list for storing AddressBook objects

	time_t rawtime; // get current date
	struct tm * timeinfo;
	int day;
	int month;
	time(&rawtime);
	timeinfo = localtime ( &rawtime );
	month = timeinfo->tm_mon; // assign current month to month variable
	month += 1;
	day = timeinfo->tm_mday; // assign current day to day variable
	mktime ( timeinfo );

	cout << "\nCurrent day is: " << day; // display current day and month
	cout << "\nCurrent month is: " << month;

	ifstream namefile; // open file for loading of list
	namefile.open("../names.txt", ifstream::in);
	namefile.is_open() ? cout << "\n\nDatabase loaded successfully." : cerr << "\nDatabase file not found";

	std::string textline; // temp variables for instantiating object and adding to list
	std::string temp_name;
	std::string temp_address;
	int tb_day{0}; // temp variables to pass as arguments for temp objects
	int tb_month{0};
	int tb_year{0};
	int ta_day{0};
	int ta_month{0};
	int ta_year{0};
	char delim{0};

	while(getline(namefile, textline)) { // loop through the file and add each person to pre-load list
		std::getline(namefile, temp_name, '|');
		std::getline(namefile, temp_address, '|');
		namefile >> tb_day;
		namefile >> delim; // get delimiter character and do nothing with it to skip it
		namefile >> tb_month;
		namefile >> delim;
		namefile >> tb_year;
		namefile >> delim;
		namefile >> ta_day;
		namefile >> delim;
		namefile >> ta_month;
		namefile >> delim;
		namefile >> ta_year;

		Birthday t_birthday(tb_year, tb_month, tb_day); // temp objects for adding to list
		Anniversary t_anniversary(ta_year, ta_month, ta_day);
		AddressBook t_person(temp_name, temp_address, t_birthday, t_anniversary);
		name_list.push_front(t_person);
	}

namefile.close(); // close file after names have been added to list


bool brexit{false}; // for the while loop below

	// while loop with nested switch statement to allow user to pick options indefinitely
	while (!brexit){
	// display menu options for user to select a choice
		cout << "\nWelcome to the address book program!"
			 << "\nPlease enter one of the following choices to begin: \n"
			 << "\n(1) Enter a new name into the address book"
			 << "\n(2) Delete a name from the address book"
			 << "\n(3) Change a name or date in the address book"
			 << "\n(4) Display the whole address book"
			 << "\n(5) Generate birthday cards"
			 << "\n(6) Generate anniversary cards"
			 << "\n(7) Exit the program" << endl;
		int n{0};
		cin >> n;// get response and store it to pass to switch statement
		switch(n) {
			case 1: {
				// -----------Enter new name into address book-----------
				string name_userinput; // variables to pass as arguments for new object into list
				string address_userinput;
				int b_day{0};
				int b_month{0};
				int b_year{0};
				int a_day{0};
				int a_month{0};
				int a_year{0};

				if ( cin.peek() == '\n' )
					cin.ignore();
				cout << "\nPlease enter your name:\t" << endl;
				getline (std::cin, name_userinput);
				cout << "\nPlease enter your address:\t" << endl;
				getline (std::cin, address_userinput);
				cout << "\nPlease enter your birthday (DD MM YYYY)"
				     << "\nIf you do not want to enter a year, enter 0" << endl;
				cin >> b_day >> b_month >> b_year;
				Birthday b(b_year, b_month, b_day);
				cout << "\nPlease enter your anniversary (DD MM YYYY)"
				     << "\nIf you do not want to enter a year, enter 0" << endl;
				cin >> a_day;
			    cin >> a_month;
		        cin >> a_year;
				Anniversary a(a_year, a_month, a_day);
				AddressBook person(name_userinput, address_userinput, b, a);
				name_list.insert(name_list.end(),person);
				break;
			}
			case 2:{
				// -----------Delete entry from address book-----------

				// Sort list before printing
				name_list.sort();

				// Print list so they can see who to delete
				for(auto& element: name_list)
					cout << element << endl;

				string removal; // instantiate string to store name for removal
				cout << "\nEnter the name of the entry you would like to remove (case sensitive)" << endl;
				if ( cin.peek() == '\n' )
					cin.ignore();
				getline(cin, removal);

				// find name in list
				auto itElem = std::find_if(name_list.begin(), name_list.end(), HasIdentifier(removal));

				// remove the name with the iterator returned from finding the name
				name_list.remove(*itElem);

				break;
			}
			case 3:{
				// -----------Change an entry-----------

				// Sort list before printing
				name_list.sort();

				// Print list so they can see who to delete
				for(auto& element: name_list)
					cout << element << endl;

				string modify; //  for storing of name to search
				cout << "\nEnter the name of the entry you would like to edit (case sensitive)" << endl;
				if ( cin.peek() == '\n' )
					cin.ignore();

				getline(cin, modify); // store name of person to edit
				// find name in list
				auto itElem = std::find_if(name_list.begin(), name_list.end(), HasIdentifier(modify));

				cout << "\nWould you like to change the:"
				     << "\n(1)Birthday"
				     << "\n(2)Anniversary"
				     << "\n(3)Name"
				     << "\nEnter a number and hit enter:\t" << endl;
				int response{0};
				cin >> response;
				if (response == 1){
					cout << "\nEnter the new birthday: \t"
					     << "\n DD (enter) MM (enter) YYYY (enter)" << endl;
					int bday_in{0}; // get temp values from user
					int bmonth_in{0};
					int byear_in{0};
					cin >> bday_in >> bmonth_in >> byear_in;
					// instantiate temp birthday to pass in as new birthday
					Birthday temp_birthday(byear_in, bmonth_in, bday_in);
					itElem->set_birthday(temp_birthday); // pass in new birthday to iterator element

				} else if (response == 2) {
					cout << "\nEnter the new anniversary: \t"
					     << "\n DD (enter) MM (enter) YYYY (enter)" << endl;
					int aday_in{0}; // get temp values from user
					int amonth_in{0};
					int ayear_in{0};
					cin >> aday_in >> amonth_in >> ayear_in;
					// instantiate temp anniversary to pass in as new anniversary
					Anniversary temp_anniversary(ayear_in, amonth_in, aday_in);
					itElem->set_anniversary(temp_anniversary); // pass in new anniversary to iterator element

				} else if (response == 3) {
						cout << "\nEnter the new name: \t" << endl;
						string new_temp_name; // get new name from user
						if (cin.peek() == '\n') {
							cin.ignore();
						}
						getline(cin, new_temp_name);
						itElem->set_name(new_temp_name); // call set_name function to pass in new name
					}
				break;
			}
			case 4:{
		// Display whole address book
				name_list.sort(); // sort first

				for(auto& element: name_list)
					cout << element << endl;  // range loop through each element and cout
				break;
			}
			case 5:{
		// Generate birthday cards
				bool b_success = false;
				for (auto &iterator : name_list) { // loop through list
					Birthday today(month, day); // create comparison with today's date

					if (iterator.get_birthday() == today) { // condition to see if any match today's date
						cout << "\nDear: " << iterator.getName()
						     << "\nHope your birthday is really wonderful and this coming year is the best yet!"
						     << "\nSincerely,"
						     << "\nYour friend Marc"
						     << endl;
						b_success = true; // indicate true so false message can display if needed
					}
				}
				if (!b_success){ // Display message if nothing matches
					cout << "\nNo birthdays match today's date.";
				}
				break;
			}
			case 6:{
		// Generate anniversary cards
				bool a_success = false;
				for (auto &iterator : name_list) { // loop through list
					Anniversary today(month, day); // create comparison with today's date

					if (iterator.get_anniversary() == today) { // compare today to iterator
						cout << "\nDear: " << iterator.getName()
						     << "\nHope your anniversary is really wonderful and this coming year is the best yet!"
						     << "\nSincerely,"
						     << "\nYour friend Marc"
						     << endl;
						a_success = true; // indicate true so false message can display if needed
					}
				}
				if (!a_success) { // display message if nothing matches
					cout << "\nNo anniversaries match today's date.";
				}
				break;
			}
			case 7:{
		// Exit
				return 0;
			}
			default:{
				cout << "Invalid entry. Please enter a number 1-7 and hit enter." << endl;
				break;
			}
		}

		cout << "\nWould you like to go back to the main menu? (y/n)" << endl;
		char answer;
		cin >> answer;
		brexit = tolower(answer) != 'y';
	};

// delete list
	name_list.clear();
	return 0;
}