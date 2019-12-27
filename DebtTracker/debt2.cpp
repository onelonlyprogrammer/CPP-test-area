#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <vector>
#include "../zyther/zyther.h"
using std::cin;
using std::cout;
using std::endl;

int command = 0;

class Debt {
   public:
    std::string name;
    double amount;

    Debt(std::string name1, double amount1) {
        name = name1;
        amount = amount1;
    }
    Debt() {
        name = "";
        amount = 0;
    }
    Debt convertToDebt(std::string str);
    //Sets up cout for Debt class
    friend std::ostream& operator<<(std::ostream& out, const Debt& d) {
        out << d.name << ", $" << d.amount;
        return out;
    }
};
std::vector<Debt> debtList;
std::vector<Debt>* debtl = &debtList;

//Converts string in proper format to Debt object
Debt Debt::convertToDebt(std::string str) {
    std::vector<std::string> tokens = splitMulti(str, ", $");

    Debt debt(tokens[0], atof(tokens[1].c_str()));
    return debt;
}

void writeFile() {
    std::ofstream file("debts.txt");
    for (Debt d : *debtl) {
        file << d << endl;
    }
    file.close();
}
//Reads debts.txt sends info to convertToDebt and pushes to debtList
void readFile() {
    std::string line;
    std::ifstream file("debts.txt");
    if (file.is_open()) {
        while (getline(file, line)) {
            Debt debt2 = debt2.convertToDebt(line);
            debtl->push_back(debt2);
        }
        file.close();
    }
	else
        cout << "File does not exist. please make now file my making new debt" << endl;
}
//Finds request and prints any occurrence of the string
void retrieve(std::string request, std::vector<Debt> dList) {
    bool found = false;
    for (Debt d : dList) {
        if (request == "all") {
            cout << d << endl;
            if (!found) {
                found = true;
            }
        }
		else if (d.name.find(request) != std::string::npos) {
            cout << d << endl;
            found = true;
        }
    }
    if (!found) cout << "Cannot find " << request << endl;
}
int main() {
    readFile();
    std::string all = "ALL";
    while (true) {
        cout << "Input command | 0: exit | 1: New debt | 2: Retrieve debt | 3: Delete debt" << endl;
        cin >> command;
		//make new debt
        if (command == 1) {
            Debt debt1;
            cout << "input name: ";
            cin >> debt1.name;
            std::string upper;
            if (debt1.name.length() == 3) {
                for (std::string::size_type i = 0; i < debt1.name.length(); ++i) {
                    upper += std::toupper(debt1.name[i]);
                }
            }
            if (upper == all) {
                cout << "all is not a valid name." << endl;
            }
			else {
                cout << "Input amount: ";
                cin >> debt1.amount;
                debtl->push_back(debt1);
                writeFile();
            }
        }
		//retreve debt
		else if (command == 2) {
            std::string request;
            cout << "Input name of debter (type all to print whole list): ";
            cin >> request;
            retrieve(request, debtList);
        }
		//delete debt
		else if (command == 3) {
            std::string request;
            cout << "Input name of debt you want to remove: ";
            cin >> request;
            for (unsigned i = 0; i < debtList.size(); ++i) {
                if (debtList[i].name.find(request) != std::string::npos) {
                    cout << "Removing " << debtList[i] << endl;
                    *debtl->erase(debtl->begin() + i);
                }
            }
            writeFile();
        }
		else if (command == 0)
            break;
    }
    return 0;
}
