#include <iostream>
#include <vector>
#include <string>
#include "../Header_files/file.h"
#include "../Header_files/contact.h"

using std::cout;
using std::cin;
using std::endl;

std::vector<Contact> contactList = readFile("test.txt");

//cycles through contactList to end to find query
void findContact() {
	std::string input;
	cout << "Input name of contact ";
	cin >> input;
	for (Contact c : contactList) {
		if (c.name == input) {
			cout << c << endl;
			return;
		}
	}
	cout << input  << " not found" << endl;
	return;
}

//gets user input and makes new contact
void addContact() {
	Contact temp;
	cin.ignore();
	cout << "Input name: ";
	std::getline(cin, temp.name);
	cout << "Input email: ";
	std::getline(cin, temp.email);
	cout << "Input address: ";
	std::getline(cin, temp.address);
	cout << "Input phone number: ";
	std::getline(cin, temp.phone);

	contactList.push_back(temp);
	writeFile("test.txt", contactList);
	return;
}

//cycles through contactList and if a contact name matches user input then deletes
void deleteContact() {
	std::string input = "";
	cin.ignore();
	cout << "Input name of contact to delete ";
	std::getline(cin, input);
	for (int i = 0; i < contactList.size(); ++i) {
		if (contactList[i].name == input) {
			contactList.erase(contactList.begin() + i);
			cout << "removed " << input << endl;
			writeFile("test.txt", contactList);
			return;
		}
	}
	cout << "Could not find " << input << endl;
	return;
}

int main() {
	while (true) {
		int command = 0;
		cout << "Input command\n" << "1|find contact. 2|add contact. 0|exit. ";
		cin >> command;
		switch (command) {
			case 0:
			 return 0;
			case 1:
			 findContact();
			 break;
			case 2:
			 addContact();
			 break;
			case 3:
			 deleteContact();
			 break;
		}
	}
	return 0;
}
