#include "pch.h"

using namespace System;

#include "NewsaveWindow.h"

using namespace System::Windows::Forms;

[STAThread]
int main()
{
  Application::EnableVisualStyles();
  Application::SetCompatibleTextRenderingDefault(false);
  Application::Run(gcnew CppCLRWinFormsProject::NewsaveWindow());
  return 0;
}