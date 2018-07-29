#include<fstream>
#include<sstream>
#include"Matrix.h"
#include"Transform.h"
#include"Figure.h"
#include"Clip.h"
#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void Main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Project9::MyForm form;
	Application::Run(%form);
}
