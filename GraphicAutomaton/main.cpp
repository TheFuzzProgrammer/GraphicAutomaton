#include "Start.h"


int startPoint() {
	GraphicAutomaton::StartUI^ USER_INTERFACE = gcnew GraphicAutomaton::StartUI(); 

	GraphicAutomaton::Application::Run(USER_INTERFACE);
	return 0;
}

//FOR TESTING
/*
int startPoint() {
	GraphicAutomaton::Application::Run(gcnew GraphicAutomaton::AutomatonSelection(6,false,4, "as5qw3rt1ui2bn3at9","aqrub"));
	return 0;
}
*/


// REGLA as5qw3rt4ui0bn1at2
// aarbqu STRING