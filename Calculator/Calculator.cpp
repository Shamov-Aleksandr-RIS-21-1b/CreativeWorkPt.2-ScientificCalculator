#include "Calculator.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]

void main(array<String^>^ arg)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Calculator::Calculator form;
	Application::Run(% form);
}
