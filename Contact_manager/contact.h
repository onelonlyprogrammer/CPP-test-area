#include <iostream>
#include <fstream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

class Contact {
	public:
		string name, email, address, phone;
		Contact() {
			name = email = address = phone = "none";
		}

		Contact(string new_name, string new_email, string new_address, string new_phone) {
			name = new_name;
			email = new_email;
			address = new_address;
			phone = new_phone;
		}

		string get(string query);
		
		//for printing
		friend std::ostream& operator<<(std::ostream& out, const Contact& c){
			out << c.name << ", " << c.email << ", " << c.address << ", " << c.phone;
			return out;
		}
};

string Contact::get(string query) {
	if (query == "name") {return name;}
	else if (query == "email") {return email;}
	else if (query == "address") {return address;}
	else if (query == "phone") {return phone;}	
	return "Invalid query: " + query + " not found";
}
