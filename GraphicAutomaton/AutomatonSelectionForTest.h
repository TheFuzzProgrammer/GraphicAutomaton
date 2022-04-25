#pragma once
#include "AFDS.h"
namespace GraphicAutomaton {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;
	using namespace AFND;

	// ref class (Or referenced classes) is an clr/cli class from Microsoft Managed C++; this is why it can't compile for linux
	// isn't compatible. i selected the Visual C++ with .NET Framework for the UI BC most of you uses Windows. and GTK takes more time.

	public ref class AutomatonSelection : public System::Windows::Forms::Form
	{
			
	public: AutomatonSelection()
		//int _number, bool _status, int _def_status, String^ _rules
		{
			InitializeComponent();
			//_number, _status, _def_status, _rules
		}
	//destructor for this class
	protected: ~AutomatonSelection()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Panel^ FormPanel;
	private: String^ Rule;
	private: status^ statd;
	private: cli::array<status^>^ QS;
	private: Mealy^ machine;
	private: System::ComponentModel::Container^ components;
	private: int q_n;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button1;
	private: bool auto_start;
	private: System::Drawing::Color^ color;
	private: System::Drawing::SolidBrush^ brush;
	private: System::Drawing::Pen^ pen;
	private: System::Drawing::Graphics^ line;
	;

#pragma region  Start UI components
		//Set the componenets int _number, bool _status, int _def_status, String^ _rules
		void InitializeComponent()
		{
			this->FormPanel = (gcnew System::Windows::Forms::Panel());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->color = gcnew System::Drawing::Color();
			this->brush = gcnew System::Drawing::SolidBrush(this->color->Lime);
			this->pen = gcnew System::Drawing::Pen(brush);
			float x1 = 259, x2 = 346;
			float y1 = 192, y2 = 192;
			this->line = this->CreateGraphics();

			try{
				this->line->DrawLine(this->pen, x1, y1, x2, y2);
			}
			catch (Exception^ e) {
				MessageBox::Show(e->Message);
			}
			this->FormPanel->SuspendLayout();
			this->SuspendLayout();
			// 
			// FormPanel
			// 
			this->FormPanel->Controls->Add(this->label2);
			this->FormPanel->Controls->Add(this->label1);
			this->FormPanel->Controls->Add(this->button1);
			this->FormPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->FormPanel->Location = System::Drawing::Point(0, 0);
			this->FormPanel->Name = L"FormPanel";
			this->FormPanel->Size = System::Drawing::Size(624, 441);
			this->FormPanel->TabIndex = 0;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Gray;
			this->label2->Location = System::Drawing::Point(259, 192);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(23, 21);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Q";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Lime;
			this->label1->Location = System::Drawing::Point(376, 192);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(23, 21);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Q";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(249, 380);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(131, 32);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Transition";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// AutomatonSelection
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 21);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(30)),
				static_cast<System::Int32>(static_cast<System::Byte>(30)));
			this->ClientSize = System::Drawing::Size(624, 441);
			this->Controls->Add(this->FormPanel);
			this->Font = (gcnew System::Drawing::Font(L"Century Gothic", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->Name = L"AutomatonSelection";
			this->Text = L"AutomatonSelection";
			this->FormPanel->ResumeLayout(false);
			this->FormPanel->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	//for testing use, shouldn't be oon final version
	public: void set_rules(String^ _Rule) {
		this->Rule = _Rule;
	}
	public: void set_q_n(int _n) {
		this->q_n = _n;
	}
	private: void set_machine(int _number, bool _status) {

		
	}

	};
}
