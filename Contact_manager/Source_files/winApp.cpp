#include "../Header_files/winApp.h"

wxIMPLEMENT_APP(winApp);

winApp::winApp() {
    
}
winApp::~winApp() {

}
bool winApp::OnInit() {
    m_frame1 = new winMain();
    m_frame1->Show();

    return true;    
}