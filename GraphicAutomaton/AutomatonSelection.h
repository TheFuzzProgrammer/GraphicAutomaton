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

	// ref class (Or referenced classes) is an clr/cli class from Microsoft Managed C++; 
	// this is why it can't compile for linux
	// isn't compatible. i selected the Visual C++ with .NET 
	// Framework for the UI BC most of you uses Windows. and GTK takes more time.

	public ref class AutomatonSelection : public System::Windows::Forms::Form
	{
	public: AutomatonSelection(int _number, bool _status, int _def_status, String^ _rules, String^ _to_process)
		{	
			this->Rule = _rules;
			this->q_n = _number;
			this->label_array = gcnew cli::array<System::Windows::Forms::Label^>(this->q_n);
			//machine instance and set up
			set_machine(_number, _status, _def_status, _rules);
			this->a_s = this->machine->GetStatus();
			this->actual_string_index = 0;
			InitializeComponent();
			this->StringContent->Text = _to_process;
			set_label_array(false, this->machine->GetStatus());
			this->show_label(this->label_array);			
			set_graphics_tools();
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
	private: Mealy^ machine;
	private: System::ComponentModel::Container^ components;
	private: int q_n, a_s, actual_string_index;
	private: System::Windows::Forms::Button^ button1;
	private: bool auto_start;
	private: System::Drawing::Color^ color;
	private: System::Drawing::SolidBrush^ brush;
	private: System::Drawing::Pen^ pen;
	private: System::Drawing::Graphics^ line;
	private: System::Windows::Forms::Label^ StringContent;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ next_symbol_lbl;
	private: System::Windows::Forms::Label^ actual_symbol_lbl;
	private: System::Windows::Forms::Label^ symbole_laebel;
	private: System::Windows::Forms::Label^ LABELTEST;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ rule_label;
	private: System::Windows::Forms::Label^ translation_lbl;
	private: System::Windows::Forms::Label^ label3;
	private: cli::array<System::Windows::Forms::Label^>^ label_array;
	private: int rpa = 10, rpb = 30;

#pragma region  Start UI components
		//Set the componenets
		void InitializeComponent()
		{
			this->FormPanel = (gcnew System::Windows::Forms::Panel());
			this->rule_label = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->LABELTEST = (gcnew System::Windows::Forms::Label());
			this->next_symbol_lbl = (gcnew System::Windows::Forms::Label());
			this->actual_symbol_lbl = (gcnew System::Windows::Forms::Label());
			this->symbole_laebel = (gcnew System::Windows::Forms::Label());
			this->StringContent = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->translation_lbl = (gcnew System::Windows::Forms::Label());
			this->FormPanel->SuspendLayout();
			this->SuspendLayout();
			// 
			// FormPanel
			// 
			this->FormPanel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(25)),
				static_cast<System::Int32>(static_cast<System::Byte>(25)));
			this->FormPanel->Controls->Add(this->translation_lbl);
			this->FormPanel->Controls->Add(this->label3);
			this->FormPanel->Controls->Add(this->rule_label);
			this->FormPanel->Controls->Add(this->label2);
			this->FormPanel->Controls->Add(this->LABELTEST);
			this->FormPanel->Controls->Add(this->next_symbol_lbl);
			this->FormPanel->Controls->Add(this->actual_symbol_lbl);
			this->FormPanel->Controls->Add(this->symbole_laebel);
			this->FormPanel->Controls->Add(this->StringContent);
			this->FormPanel->Controls->Add(this->label1);
			this->FormPanel->Controls->Add(this->button1);
			this->FormPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->FormPanel->Location = System::Drawing::Point(0, 0);
			this->FormPanel->Name = L"FormPanel";
			this->FormPanel->Size = System::Drawing::Size(624, 441);
			this->FormPanel->TabIndex = 0;
			// 
			// rule_label
			// 
			this->rule_label->AutoSize = true;
			this->rule_label->ForeColor = System::Drawing::SystemColors::ActiveCaption;
			this->rule_label->Location = System::Drawing::Point(3, 350);
			this->rule_label->Name = L"rule_label";
			this->rule_label->Size = System::Drawing::Size(0, 21);
			this->rule_label->TabIndex = 9;
			this->rule_label->Text = this->Rule;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
			this->label2->Location = System::Drawing::Point(3, 322);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(51, 21);
			this->label2->TabIndex = 8;
			this->label2->Text = L"Rule: ";
			// 
			// LABELTEST
			// 
			this->LABELTEST->AutoSize = true;
			this->LABELTEST->ForeColor = System::Drawing::Color::MediumTurquoise;
			this->LABELTEST->Location = System::Drawing::Point(561, 407);
			this->LABELTEST->Name = L"LABELTEST";
			this->LABELTEST->Size = System::Drawing::Size(0, 21);
			this->LABELTEST->TabIndex = 7;
			// 
			// next_symbol_lbl
			// 
			this->next_symbol_lbl->AutoSize = true;
			this->next_symbol_lbl->ForeColor = System::Drawing::Color::PaleGreen;
			this->next_symbol_lbl->Location = System::Drawing::Point(488, 350);
			this->next_symbol_lbl->Name = L"next_symbol_lbl";
			this->next_symbol_lbl->Size = System::Drawing::Size(21, 21);
			this->next_symbol_lbl->TabIndex = 6;
			this->next_symbol_lbl->Text = L"b";
			// 
			// actual_symbol_lbl
			// 
			this->actual_symbol_lbl->AutoSize = true;
			this->actual_symbol_lbl->ForeColor = System::Drawing::Color::Red;
			this->actual_symbol_lbl->Location = System::Drawing::Point(381, 350);
			this->actual_symbol_lbl->Name = L"actual_symbol_lbl";
			this->actual_symbol_lbl->Size = System::Drawing::Size(21, 21);
			this->actual_symbol_lbl->TabIndex = 5;
			this->actual_symbol_lbl->Text = L"a";
			// 
			// symbole_laebel
			// 
			this->symbole_laebel->AutoSize = true;
			this->symbole_laebel->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
			this->symbole_laebel->Location = System::Drawing::Point(381, 322);
			this->symbole_laebel->Name = L"symbole_laebel";
			this->symbole_laebel->Size = System::Drawing::Size(207, 21);
			this->symbole_laebel->TabIndex = 4;
			this->symbole_laebel->Text = L"Last readed  Next symbol";
			// 
			// StringContent
			// 
			this->StringContent->AutoSize = true;
			this->StringContent->ForeColor = System::Drawing::Color::MediumSpringGreen;
			this->StringContent->Location = System::Drawing::Point(166, 349);
			this->StringContent->Name = L"StringContent";
			this->StringContent->Size = System::Drawing::Size(115, 21);
			this->StringContent->TabIndex = 3;
			this->StringContent->Text = L"StringContent";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
			this->label1->Location = System::Drawing::Point(166, 322);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(57, 21);
			this->label1->TabIndex = 2;
			this->label1->Text = L"String:";
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Azure;
			this->button1->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->button1->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Aqua;
			this->button1->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Location = System::Drawing::Point(249, 380);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(131, 32);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Transition";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &AutomatonSelection::button1_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
			this->label3->Location = System::Drawing::Point(381, 291);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(55, 21);
			this->label3->TabIndex = 10;
			this->label3->Text = L"Result";
			// 
			// translation_lbl
			// 
			this->translation_lbl->AutoSize = true;
			this->translation_lbl->ForeColor = System::Drawing::Color::Orchid;
			this->translation_lbl->Location = System::Drawing::Point(463, 291);
			this->translation_lbl->Name = L"translation_lbl";
			this->translation_lbl->Size = System::Drawing::Size(0, 21);
			this->translation_lbl->TabIndex = 11;
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
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"AutomatonSelection";
			this->FormPanel->ResumeLayout(false);
			this->FormPanel->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

	//Final methods
	private: cli::array<System::Windows::Forms::Label^>^ label_init(cli::array<System::Windows::Forms::Label^>^ _array, bool _auto_status, int _default_status) {
		int random_def_status = 0 + rand()% this->q_n;
		for (int x = 0; x < _array->Length; x++) {
			System::Windows::Forms::Label^ label;
			label = gcnew System::Windows::Forms::Label();
			switch (_auto_status)
			{
			case true: {
				if (x == random_def_status) {
					label = this->set_label(label, true, x);
				}
				else {
					label = this->set_label(label, false, x);
				}
				break;
			}
			case false: {
				if (x == _default_status) {
					label = this->set_label(label, true, x);
				}
				else {
					label = this->set_label(label, false, x);
				}
				break;
			}
			default:
				break;
			}
			_array[x] = label;
			
		}
		return _array;
	}
	
	private: void show_label(cli::array<System::Windows::Forms::Label^>^ _array){
		int position_x, position_y;
		position_x = 0;
		position_y = this->Height / 2 - 100;
		this->ResumeLayout(true);
		this->FormPanel->ResumeLayout(true);
		for (int x = 0; x < _array->Length; x++) {
			position_x = this->calculate_space(position_x + 23 );
			_array[x]->Location = System::Drawing::Point(position_x, position_y);
			this->FormPanel->Controls->Add(_array[x]);
		}
		this->FormPanel->SuspendLayout();
		this->SuspendLayout();
		
	}

	private: int calculate_space(int _actual) {
		_actual += (624 - (23 * this->q_n)) / (this->q_n + 1);
		return _actual;
	}

	private: System::Windows::Forms::Label^ set_label(System::Windows::Forms::Label^ _label, bool _enabled, int _index) {
		this->ResumeLayout(true);
		this->FormPanel->ResumeLayout(true);
		_label->AutoSize = true;
		_label->Size = System::Drawing::Size(23, 21);
		_label->Name = L"status" + _index.ToString();
		_label->Text = L"Q" + _index.ToString();
		_label->TabIndex = _index + 10;
		switch (_enabled) {
		case true: {	
			_label->BackColor = System::Drawing::Color::Lime;
			break;
		}
		case false: {
			_label->BackColor = System::Drawing::Color::Gray;
			break;
		}
		default:
			break;
		}
		return _label;
		this->FormPanel->SuspendLayout();
		this->SuspendLayout();

	}

	private: void set_label_array(bool _status, int _def_status) {
		this->label_array = this->label_init(this->label_array, _status, _def_status);
		
	}

	private: void graphic_update() {
		for (int x = 0; x < this->label_array->Length; x++) {
			if (x == a_s) {
				this->label_array[x] = this->set_label(this->label_array[x], true, x);
			}
			else {
				this->label_array[x] = this->set_label(this->label_array[x], false, x);
				
			}
		}
	}
	
	private:void set_graphics_tools() {
		this->color = gcnew System::Drawing::Color();
		this->brush = gcnew System::Drawing::SolidBrush(this->color->Lime);
		this->pen = gcnew System::Drawing::Pen(Color::FromArgb(125, 255, 255, 255), 4);
		this->pen->StartCap = System::Drawing::Drawing2D::LineCap::ArrowAnchor;
		this->pen->EndCap = System::Drawing::Drawing2D::LineCap::RoundAnchor;
	}

	private: void set_machine(int _number, bool _status, int _def_status, String^ _rules) {
		this->machine = gcnew Mealy(_number, _status, _def_status);
		this->machine->set_condition(_rules);
	}

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		this->a_s = this->machine->GetStatus();
		Point last_status_point, actual_status_point, aux_point, aux_point2;
		last_status_point = this->label_array[a_s]->Location;
		if (this->actual_string_index == this->StringContent->Text->Length) {
			MessageBox::Show("Termino de recorrido. resultado es: " + this->translation_lbl->Text);
		}
		else {
			String^ test = this->machine->update(this->StringContent->Text[this->actual_string_index].ToString());
			try{
				this->next_symbol_lbl->Text = this->StringContent->Text[actual_string_index + 1].ToString();
				this->actual_symbol_lbl->Text = this->StringContent->Text[actual_string_index].ToString();
				this->actual_string_index += 1;
				this->translation_lbl->Text = this->translation_lbl->Text + test;
			}
			catch(Exception^ e) {
				MessageBox::Show("Ultimo Simbolo alcanzado");
				this->actual_string_index += 1;
			}
		}
		this->a_s = this->machine->GetStatus();
		this->LABELTEST->Text = a_s.ToString() + this->machine->q_status[this->machine->a_status]->ToStr();
		this->graphic_update();
		actual_status_point = this->label_array[a_s]->Location;
		actual_status_point.X += 13;
		last_status_point.X += 13;
		aux_point.X = last_status_point.X + rpa;
		aux_point.Y = last_status_point.Y - rpb;
		aux_point2.X = actual_status_point.X + rpa;
		aux_point2.Y = actual_status_point.Y - rpb;
		this->pen->Color = Color::Lime; //x2-40 x1+40
		if (actual_status_point.X != last_status_point.X){
			Graphics^ pointer = this->FormPanel->CreateGraphics();
			this->pen->Color = Color::FromArgb(125, 35, 242, 97);
			pointer->DrawBezier(this->pen, actual_status_point, aux_point2, aux_point, last_status_point);
			for (int x = 0; x < 256; x++) {
				this->pen->Color = Color::FromArgb(200,0,x,0);
				pointer->DrawBezier(this->pen, actual_status_point, aux_point2, aux_point, last_status_point);
				_sleep(5);
			}
		}
		this->rpb += 10;
		
	}
	
};
}
