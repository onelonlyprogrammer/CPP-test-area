#include <iostream>
#include <vector>
#include <string>
#include "file.h"
#include "contact.h"

using std::cout;
using std::cin;
using std::endl;

std::vector<Contact> contactList = readFile("test.txt");

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
	cout << "Input not found" << endl;
	return;
}

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

	//contactList.push_back(temp);
	//writeFile("test.txt", contactList);
	return;
}

int main() {
	while (true) {
		int command = 0;
		cout << "Input command\n" << "1|find contact. 2|add contact. ";
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
		}
	}
	return 0;
}
