#include <iostream>
#include <fstream>
#include <vector>
using std::cout;
using std::cin;
using std::endl;
using std::ofstream;

int command = 0;
std::string debt = "", name = "", request = "";
std::vector<std::string> debts;

void writeFile(){
		ofstream file;
		file.open("debts.txt");

	for (std::string& v : debts){
		file << v << endl;
	}
	file.close();
}
void readFile(){
	std::string line;

	std::ifstream file("debts.txt");
	if (file.is_open()){
		while (getline(file, line)){
			debts.push_back(line);			
		}
	}
	file.close();
}
int main(){
	readFile();
	cout << "input command: ";
	cin >> command;
	if (command == 1){
		cout << "input name of debter" << endl;
		cin >> name;
		cout << "input amount due" << endl;
		cin >> debt;
		debts.push_back(name + ", " + debt);
		writeFile();
	}
	else if (command == 2){
		bool found = false;
		cout << "input name of debter" << endl;
		cin >> request;
		for(std::string d : debts){
			if (d.find(request) != std::string::npos){
				cout << "found " << d << endl;
				found = true;
			}
		}
		if (!found){
		cout << request << " not found" << endl;
		}
	}
	return 0;
}

