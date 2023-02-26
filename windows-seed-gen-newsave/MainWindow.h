#pragma once
#include "NewsaveWindow.h"
#include "Tree.h"
namespace CppCLRWinFormsProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MainWindow
	/// </summary>
	public ref class MainWindow : public System::Windows::Forms::Form
	{
	public:
		MainWindow(void)
		{
			InitializeComponent();
			tabControl1->Dock = DockStyle::Fill;
			AddTabs();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainWindow()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TabControl^ tabControl1;
	private: System::Windows::Forms::TabPage^ NewsaveSeedGenTab;
	private: System::Windows::Forms::TabPage^ TreeTab;


	protected:



	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->NewsaveSeedGenTab = (gcnew System::Windows::Forms::TabPage());
			this->TreeTab = (gcnew System::Windows::Forms::TabPage());
			this->tabControl1->SuspendLayout();
			this->SuspendLayout();
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->NewsaveSeedGenTab);
			this->tabControl1->Controls->Add(this->TreeTab);
			this->tabControl1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tabControl1->Location = System::Drawing::Point(0, 0);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(982, 553);
			this->tabControl1->TabIndex = 0;
			// 
			// NewsaveSeedGenTab
			// 
			this->NewsaveSeedGenTab->Location = System::Drawing::Point(4, 25);
			this->NewsaveSeedGenTab->Name = L"NewsaveSeedGenTab";
			this->NewsaveSeedGenTab->Padding = System::Windows::Forms::Padding(3);
			this->NewsaveSeedGenTab->Size = System::Drawing::Size(974, 524);
			this->NewsaveSeedGenTab->TabIndex = 0;
			this->NewsaveSeedGenTab->Text = L"Newsave-Seed-Gen";
			this->NewsaveSeedGenTab->UseVisualStyleBackColor = true;
			// 
			// TreeTab
			// 
			this->TreeTab->Location = System::Drawing::Point(4, 25);
			this->TreeTab->Name = L"TreeTab";
			this->TreeTab->Padding = System::Windows::Forms::Padding(3);
			this->TreeTab->Size = System::Drawing::Size(974, 671);
			this->TreeTab->TabIndex = 1;
			this->TreeTab->Text = L"Tree";
			this->TreeTab->UseVisualStyleBackColor = true;
			// 
			// MainWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(982, 553);
			this->Controls->Add(this->tabControl1);
			this->Name = L"MainWindow";
			this->Text = L"MainWindow";
			this->tabControl1->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private:
		void AddTabs() {
			//NewsaveWindow
			add_tab(gcnew NewsaveWindow(), NewsaveSeedGenTab);
			add_tab(gcnew Tree(), TreeTab);


		}
		void add_tab(Form^ form, TabPage^% tab) {
			form->TopLevel = false;
			form->Dock = DockStyle::Fill;
			tab->Controls->Add(form);
			form->Show();
		}
	};
}
