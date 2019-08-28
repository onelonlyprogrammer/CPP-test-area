#include <iostream>
#include <string>
#include <typeinfo>
#include <vector>

using std::string;

class Zyther {
   public:
    string strip_one(string str, char todelete);
    string strip_multi(string str, string todelete);
    std::vector<string> split_one(string str, char devider);
    std::vector<string> split_multi(string str, string devider);
};

string Zyther::strip_one(string str, char todelete) {
    string stripped;
    for (int i = 0; i < str.length(); ++i) {
        if (str[i] != todelete) {
            stripped += str[i];
        }
    }
    return stripped;
}

string Zyther::strip_multi(string str, string todelete) {
    string stripped, temp;
    for (int i = 0; i < str.length(); ++i) {
        for (int s = 0; s < todelete.length(); ++s) {	
            temp += str[s + i];
        }
        if (temp != todelete) {
			stripped += str[i];
        }
		else {str.erase(i, todelete.length() - 1);}
		temp = "";
    }
	return stripped;
}

std::vector<string> Zyther::split_one(string str, char devider) {
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

std::vector<string> Zyther::split_multi(string str, string devider) {
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
