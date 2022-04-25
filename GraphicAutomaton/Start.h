#pragma once
#include "AutomatonSelection.h"

namespace GraphicAutomaton {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;

	public ref class StartUI : public System::Windows::Forms::Form
	{
	public: StartUI(void)
		{
			InitializeComponent();
		}

	protected: ~StartUI()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ ContainerPanel;
	private: System::Windows::Forms::Panel^ FormPanel;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ rule_box;
	private: System::Windows::Forms::Button^ Start_btn;
	private: System::Windows::Forms::ComboBox^ status_number;
	private: System::Windows::Forms::CheckBox^ random_start;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ word_input;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ default_status_input;
	private: System::Windows::Forms::Label^ label3;
	private: System::ComponentModel::Container^ components;

#pragma region 
		void InitializeComponent(void)
		{
			this->ContainerPanel = (gcnew System::Windows::Forms::Panel());
			this->FormPanel = (gcnew System::Windows::Forms::Panel());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->default_status_input = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->word_input = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->status_number = (gcnew System::Windows::Forms::ComboBox());
			this->random_start = (gcnew System::Windows::Forms::CheckBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->rule_box = (gcnew System::Windows::Forms::TextBox());
			this->Start_btn = (gcnew System::Windows::Forms::Button());
			this->ContainerPanel->SuspendLayout();
			this->FormPanel->SuspendLayout();
			this->SuspendLayout();
			// 
			// ContainerPanel
			// 
			this->ContainerPanel->Controls->Add(this->FormPanel);
			this->ContainerPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->ContainerPanel->Location = System::Drawing::Point(0, 0);
			this->ContainerPanel->Name = L"ContainerPanel";
			this->ContainerPanel->Size = System::Drawing::Size(624, 441);
			this->ContainerPanel->TabIndex = 0;
			// 
			// FormPanel
			// 
			this->FormPanel->Controls->Add(this->label4);
			this->FormPanel->Controls->Add(this->default_status_input);
			this->FormPanel->Controls->Add(this->label3);
			this->FormPanel->Controls->Add(this->word_input);
			this->FormPanel->Controls->Add(this->label2);
			this->FormPanel->Controls->Add(this->status_number);
			this->FormPanel->Controls->Add(this->random_start);
			this->FormPanel->Controls->Add(this->label1);
			this->FormPanel->Controls->Add(this->rule_box);
			this->FormPanel->Controls->Add(this->Start_btn);
			this->FormPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->FormPanel->Location = System::Drawing::Point(0, 0);
			this->FormPanel->Name = L"FormPanel";
			this->FormPanel->Size = System::Drawing::Size(624, 441);
			this->FormPanel->TabIndex = 1;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
			this->label4->Location = System::Drawing::Point(336, 253);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(93, 21);
			this->label4->TabIndex = 13;
			this->label4->Text = L"Start at (Q)";
			// 
			// default_status_input
			// 
			this->default_status_input->BackColor = System::Drawing::SystemColors::ScrollBar;
			this->default_status_input->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->default_status_input->Location = System::Drawing::Point(435, 255);
			this->default_status_input->Name = L"default_status_input";
			this->default_status_input->Size = System::Drawing::Size(38, 20);
			this->default_status_input->TabIndex = 12;
			this->default_status_input->Text = L"0";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
			this->label3->Location = System::Drawing::Point(145, 289);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(50, 21);
			this->label3->TabIndex = 11;
			this->label3->Text = L"Word";
			// 
			// word_input
			// 
			this->word_input->BackColor = System::Drawing::SystemColors::ScrollBar;
			this->word_input->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->word_input->Location = System::Drawing::Point(149, 323);
			this->word_input->Name = L"word_input";
			this->word_input->Size = System::Drawing::Size(324, 20);
			this->word_input->TabIndex = 10;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
			this->label2->Location = System::Drawing::Point(145, 83);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(158, 21);
			this->label2->TabIndex = 9;
			this->label2->Text = L"Number of statuses";
			// 
			// status_number
			// 
			this->status_number->AutoCompleteCustomSource->AddRange(gcnew cli::array< System::String^  >(10) {
				L"1", L"2", L"3", L"4",
					L"5", L"6", L"7", L"8", L"9", L"10"
			});
			this->status_number->BackColor = System::Drawing::SystemColors::ControlDark;
			this->status_number->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->status_number->Font = (gcnew System::Drawing::Font(L"Century Gothic", 9.75F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->status_number->ForeColor = System::Drawing::SystemColors::InactiveCaptionText;
			this->status_number->FormatString = L"N0";
			this->status_number->FormattingEnabled = true;
			this->status_number->Items->AddRange(gcnew cli::array< System::Object^  >(9) {
				L"2", L"3", L"4", L"5", L"6", L"7", L"8", L"9",
					L"10"
			});
			this->status_number->Location = System::Drawing::Point(149, 122);
			this->status_number->Name = L"status_number";
			this->status_number->Size = System::Drawing::Size(117, 24);
			this->status_number->TabIndex = 8;
			this->status_number->Text = L"2";
			// 
			// random_start
			// 
			this->random_start->AutoSize = true;
			this->random_start->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->random_start->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
			this->random_start->Location = System::Drawing::Point(149, 250);
			this->random_start->Name = L"random_start";
			this->random_start->Size = System::Drawing::Size(138, 25);
			this->random_start->TabIndex = 7;
			this->random_start->Text = L"Random start\?";
			this->random_start->UseVisualStyleBackColor = true;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
			this->label1->Location = System::Drawing::Point(145, 163);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(43, 21);
			this->label1->TabIndex = 6;
			this->label1->Text = L"Rule";
			// 
			// rule_box
			// 
			this->rule_box->BackColor = System::Drawing::SystemColors::ScrollBar;
			this->rule_box->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->rule_box->Location = System::Drawing::Point(149, 195);
			this->rule_box->Name = L"rule_box";
			this->rule_box->Size = System::Drawing::Size(324, 20);
			this->rule_box->TabIndex = 5;
			// 
			// Start_btn
			// 
			this->Start_btn->BackColor = System::Drawing::Color::Lime;
			this->Start_btn->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)),
				static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(30)));
			this->Start_btn->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Green;
			this->Start_btn->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->Start_btn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Start_btn->Location = System::Drawing::Point(525, 394);
			this->Start_btn->Name = L"Start_btn";
			this->Start_btn->Size = System::Drawing::Size(87, 35);
			this->Start_btn->TabIndex = 4;
			this->Start_btn->Text = L"Try";
			this->Start_btn->UseVisualStyleBackColor = false;
			this->Start_btn->Click += gcnew System::EventHandler(this, &StartUI::button1_Click);
			// 
			// StartUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 21);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(30)),
				static_cast<System::Int32>(static_cast<System::Byte>(30)));
			this->ClientSize = System::Drawing::Size(624, 441);
			this->Controls->Add(this->ContainerPanel);
			this->Font = (gcnew System::Drawing::Font(L"Century Gothic", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(640, 480);
			this->MinimizeBox = false;
			this->MinimumSize = System::Drawing::Size(640, 480);
			this->Name = L"StartUI";
			this->Opacity = 0.95;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"GraphicalAutomaton By Fuzz";
			this->TransparencyKey = System::Drawing::Color::Transparent;
			this->ContainerPanel->ResumeLayout(false);
			this->FormPanel->ResumeLayout(false);
			this->FormPanel->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
		template <class TEMPLATE_FORM>
		void open_panel(TEMPLATE_FORM S_FORM) {
			if (this->ContainerPanel->Controls->Count > 0)
				this->ContainerPanel->Controls->RemoveAt(0);
			S_FORM->TopLevel = false;
			S_FORM->Dock = DockStyle::Fill;
			this->ContainerPanel->Controls->Add(S_FORM);
			this->ContainerPanel->Tag = S_FORM;
			S_FORM->Show();
		}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		if (this->rule_box->Text->Length / Conversions::FromCharToInteger(this->status_number->Text[0])==3)
		{
			AutomatonSelection^ S_FORM = gcnew AutomatonSelection(Conversions::FromCharToInteger(this->status_number->Text[0]), 
																	this->random_start->Checked, 
																	Conversions::FromCharToInteger(this->default_status_input->Text[0]),
																	this->rule_box->Text, word_input->Text);
			//6,false,4, "as5qw3rt1ui2bn3at9",""
			this->label2->Text = (Conversions::FromCharToInteger(this->status_number->Text[0]) * 2).ToString();
			open_panel(S_FORM);
		}
		else {
			MessageBox::Show("Las reglas no tienen coherencia en este ambito");
		}

	}
};
}
