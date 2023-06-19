#pragma comment(linker, "/subsystem:windows /ENTRY:mainCRTStartup")
#include "MainForm.h"
#pragma comment(linker, "/subsystem:windows /ENTRY:mainCRTStartup")

using namespace System;
using namespace System::Windows::Forms;
using namespace std;

int main()
{
	Application::EnableVisualStyles();
	PopBallGame::MainForm form;
	manager = new Manager(form.frame->Width, form.frame->Height);
	Application::Run(% form);
	delete manager;
}



