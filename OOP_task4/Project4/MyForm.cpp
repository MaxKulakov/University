 #include"MyForm.h"
#include"Classes.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void Main(array<String^>^ args) {
	 Application::EnableVisualStyles();
	 Application::SetCompatibleTextRenderingDefault(false);
	 Project4::MyForm form;
	 Application::Run(%form);
	
}
