#include <iostream>
#include <string>
#include <typeinfo>
#include <vector>

using std::string;

class Zyther {
   public:
    string stripOne(string str, char toDelete);
    string stripMulti(string str, string toDelete);
	bool isIn(string str, const std::string& toFind);
    std::vector<string> splitOne(string str, char devider);
    std::vector<string> splitMulti(string str, string devider);
};

string Zyther::stripOne(string str, char toDelete) {
    string stripped;
    for (int i = 0; i < str.length(); ++i) {
        if (str[i] != toDelete) {
            stripped += str[i];
        }
    }
    return stripped;
}
string Zyther::stripMulti(string str, string toDelete) {
    string stripped, temp;
    for (int i = 0; i < str.length(); ++i) {
        for (int s = 0; s < toDelete.length(); ++s) {	
            temp += str[s + i];
        }
        if (temp != toDelete) {
			stripped += str[i];
        }
		else {str.erase(i, toDelete.length() - 1);}
		temp = "";
    }
	return stripped;
}

bool Zyther::isIn(string str, const std::string& toFind) {
    string stripped, temp;
    for (int i = 0; i < str.length(); ++i) {
        for (int s = 0; s < toFind.length(); ++s) {	
            temp += str[s + i];
        }
        if (temp == toFind) {
			return true;
        }
        temp = "";
    }
	return false;
}

std::vector<string> Zyther::splitOne(string str, char devider) {
	std::vector<string> splitVec;
	string splitted;
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

std::vector<string> Zyther::splitMulti(string str, string devider) {
    std::vector<string> splitVec;
    string splitted, temp;
    bool first = false;
    for (int i = 0; i < str.length(); ++i) {
        for (int s = 0; s < devider.length(); ++s) {
            temp += str[s + i];
        }
        if (temp == devider && first) {
            splitted.erase(0, devider.length() - 1);

			splitVec.push_back(splitted);
            splitted = "";
        }
		else if (temp == devider && !first) {
            first = true;
            splitVec.push_back(splitted);
            splitted = "";
        }
		else
            splitted += str[i];
        temp = "";
    }
    splitted.erase(0, devider.length() - 1);
    splitVec.push_back(splitted);
	return splitVec;
}
