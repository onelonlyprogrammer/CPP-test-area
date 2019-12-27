#include "../Header_files/winMain.h"
#include "../Header_files/contactHandler.h"
#include "../../zyther/zyther.h"

wxBEGIN_EVENT_TABLE(winMain, wxFrame)
	EVT_BUTTON(10001, winMain::make_btnClicked)
	EVT_BUTTON(10002, winMain::find_btnClicked)
	EVT_BUTTON(10003, winMain::delete_btnClicked)
wxEND_EVENT_TABLE()

winMain::winMain() : wxFrame(nullptr, wxID_ANY, "tester",  wxPoint(30, 30), wxSize(800, 600)) {
	make_btn = new wxButton(this,  10001, "Make", wxPoint(10, 10), wxSize(150, 50));
	find_btn = new wxButton(this,  10002, "Find", wxPoint(10, 70), wxSize(150, 50));
	delete_btn = new wxButton(this,  10003, "Delete", wxPoint(10, 130), wxSize(150, 50));
	input_txt = new wxTextCtrl(this, wxID_ANY, "", wxPoint(300, 10), wxSize(250, 25));
	output_list = new wxListBox(this, wxID_ANY, wxPoint(275, 60), wxSize(300, 300));
}
winMain::~winMain() {
	
}
void winMain::make_btnClicked(wxCommandEvent &evt) {
	output_list->Clear();
	output_list->AppendString(addContact(splitMulti(input_txt->GetValue().ToStdString(), ", ")));
	evt.Skip();
}
void winMain::find_btnClicked(wxCommandEvent &evt) {
	output_list->Clear();
	if (input_txt->GetValue() == "all") {
		std::vector<string> temp = getAllContacts();
		for (string s : temp) {
			output_list->AppendString(s);
		}
	} 
	else {
		output_list->AppendString(findContact(input_txt->GetValue().ToStdString()));	
	}
	
	evt.Skip();
}
void winMain::delete_btnClicked(wxCommandEvent &evt) {
	output_list->Clear();
	output_list->AppendString(deleteContact(input_txt->GetValue().ToStdString()));
	evt.Skip();
}
