#include <iostream>
#include <fstream>
#include <vector>
#include "contact.h"
#include "../zyther/zyther.h"

Zyther zyther;

void writeFile(std::string fileName, std::vector<Contact> list) {
	std::ofstream file(fileName);

	for (Contact a : list) {
		file << a << endl;
	}

	file.close();
	return;
}
std::vector<Contact> readFile(std::string fileName) {
	std::string line;
	std::vector<Contact> ret;
	std::ifstream file(fileName);
	if (file.is_open()) {
		while (getline(file, line)) {
			std::vector<std::string> temp = zyther.splitMulti(line, ", ");
			Contact contact(temp[0], temp[1], temp[2], temp[3]);
			ret.push_back(contact);
		}
	}
	return ret;
}
