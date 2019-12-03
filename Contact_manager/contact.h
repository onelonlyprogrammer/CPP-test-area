#ifndef Included_NameModel_H
#define Included_NameModel_H

#include <iostream>
#include <fstream>

using std::string;

class Contact {
	public:
		string name, email, address, phone;
		
		//default constructor
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
#endif
