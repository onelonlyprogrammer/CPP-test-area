#include <iostream>
#include "boost/algorithm/string.hpp"
#include <stdlib.h>
#include <fstream>
#include <vector>
using std::cout;
using std::cin;
using std::endl;

class Debt{
	public:
	std::string name;
	double amount;

	Debt convertToDebt(std::string str);
	//Sets up cout for Debt class
	friend std::ostream& operator << (std::ostream& out, const Debt& d){
		out << d.name << ", " << d.amount;
		return out;
	}
};

//Converts string in proper format to Debt object
Debt Debt::convertToDebt(std::string str){
	Debt debt;
	
	std::vector<std::string> tokens;
	boost::split(tokens, str, boost::is_any_of(","));

	debt.name = tokens[0], debt.amount = atof(tokens[1].c_str());
	return debt;
}

int command = 0;
std::vector<Debt> debtList;
std::vector<Debt> *debtl = &debtList;

void writeFile(){
	std::ofstream file ("debts.txt");
	for (Debt d : *debtl){
	file << d << endl;
	}
	file.close();
}
//Reads debts.txt sends info to convertToDebt and pushes to debtList
void readFile(){
	std::string line;
	std::ifstream file ("debts.txt");
	if (file.is_open()){
		while (getline (file, line)){
			Debt debt2 = debt2.convertToDebt(line);
			debtl->push_back(debt2);
			}
		file.close();
	}
	else cout << "file read error";
}
//Finds request and prints any occurrence of the string
void retrieve(std::string request, std::vector<Debt> dList){
	bool found = false;
	for (Debt d : dList){
		if (request == "all"){
			cout << d << endl;
			if (!found){
				found = true;
			}
		}
		else if (d.name.find(request) != std::string::npos){
			cout << d << endl;
			found = true;
		}
	}
	if (!found) cout << "cannot find " << request << endl;
}
int main(){
	readFile();
	while (true){
		cout << "input command: ";
		cin >> command;
		if (command == 1){
			Debt debt1;
			cout << "input name" << endl;
			cin >> debt1.name;
			cout << "input amount" << endl;
			cin >> debt1.amount;
			debtl->push_back(debt1);
			writeFile();
		}
		else if (command == 2){
			std::string request;
			cout << "input name of debter: ";
			cin >> request;
			retrieve(request, debtList);
		}
		else if (command == 3){
			std::string request;
			cout << "input name of debt you want to remove: ";
			cin >> request;
			for (unsigned i = 0; i < debtList.size(); ++i){
				if (debtList[i].name.find(request) != std::string::npos){
					cout << "removing " << debtList[i] << endl;
					*debtl->erase(debtl->begin() +i);
				}
			}
			writeFile();
		}
		else break;
	}
	return 0;
}
