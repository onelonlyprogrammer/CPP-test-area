#include <iostream>
#include <vector>
#include <string>
#include "file.h"
#include "contact.h"

using std::cout;
using std::cin;
using std::endl;

std::vector<Contact> contactList = readFile("test.txt");

//cycles through contactList to end to find query
std::string findContact(string input) {
	for (Contact c : contactList) {
		if (c.name == input) {
			cout << c << endl;
			return c.toString();
		}
	}
	cout << input  << " not found" << endl;
	return input + " not found";
}

std::vector<string> getAllContacts() {
	std::vector<string> ret;
	for (Contact c : contactList) {
		ret.push_back(c.toString());
	}
	return ret;
}

//gets user input and makes new contact
std::string addContact(std::vector<string> args) {
	if (args.size() == 4) {
		Contact temp(args[0], args[1], args[2], args[3]);
		contactList.push_back(temp);
		writeFile("test.txt", contactList);
		
		return args[0] + " was added succesfully";
	}
	return "Invalid input";
}

//cycles through contactList and if a contact name matches user input then deletes
std::string deleteContact(string input) {
	for (int i = 0; i < contactList.size(); ++i) {
		if (contactList[i].name == input) {
			contactList.erase(contactList.begin() + i);
			cout << "Removed " << input << endl;
			writeFile("test.txt", contactList);
			return "Removed " + input;
		}
	}
	cout << "Could not find " << input << endl;
	return "Could not find " + input;
}
