#include <iostream>
#include <string>
#include <vector>

class Spire {
	public:
	std::vector<std::string> split(std::string str, char devider);
};

std::vector<std::string> Spire::split(std::string str, char devider) {
	std::vector<std::string> splitVec;
	std::string splitted;
	for (int i = 0; i < str.length(); ++i) {
		if (str[i] != devider) {
			splitted += str[i];
		}
		else {
			splitVec.push_back(splitted);
			splitted = "";
		}
	}
	splitVec.push_back(splitted);
	return splitVec;
}
