#pragma once
#include <iostream>
#include <vector>
#include "types.h"
#ifndef String, Vector, ToInt
#define SString std::string
#define Vector std::vector
#define ToInt Conversions::FromCharToInteger
#endif


namespace AFND {
	using namespace cli;
	using namespace System;

	ref struct status {

		public: cli::array<String^>^ symbols;

		public: int code;

		public: status(String^, int); //constructor

		//Sets the symbols for every status {input_recognized, symbol_that_returns, status_to_go->Next.code}
		public: void s_symbol(String^ _symbol, String^ _action, String^ _goes_to) {
				this->symbols[0] = _symbol;
				this->symbols[1] = _action;
				this->symbols[2] = _goes_to;
		}

		//Sets the status code 
		public: void set_code(int _code) {
				this->code = _code;
		}

		//returns the array of symbols as System::String^ ref obj
		String^ ToStr() {
			String^ temp_str = "" + symbols[0] + symbols[1]+ symbols[2];
			return temp_str;
		}

	};


	ref class Mealy {

		private: const unsigned long long IN = 0, OUT = 1, TRA = 2; // Indexes US LL For prevent overflow

		public: cli::array<status^>^ q_status; // ARRAY[POSITION] is STATUS so ARRAY[POSITION].SYMBOLS{IN, OUT, TRANSITION (N OR STATUS)} where {char, char, char}
		public: int a_status;				  // ACTUAL STATUS is INDEX of the vector wich is the status where the machine is.
			System::String^ word = gcnew System::String("");
			System::String^ traduction = gcnew System::String("");
			//Vector<System::String>* transition_func;

		public:	Mealy(int, bool, int);		  // constructor
		
		//sets the conditions for transitions on every status that the automaton can take (or not)
		public: bool set_condition(System::String^ _condition) {
					if (_condition->Length / 3 != q_status->Length ){ //rejects invalid transition functions
						return false;
					}
					else {
						int index_increase = 0;

						for (int C = 0; C < this->q_status->Length; C++) {

							switch (index_increase) {
							case 0: if (C > 0) index_increase += 3;
								break;
							default: index_increase += 3;
							}
							q_status[C] = gcnew status(_condition[IN + index_increase].ToString() + _condition[OUT + index_increase].ToString() + _condition[TRA + index_increase].ToString(), C);
						}
						return true;
					}
				}

		//changes the actal status / makes the transitions
	public: System::String^ update(String^ _symbol) {

		if(this->q_status[a_status]->ToStr()[0].ToString() == _symbol->ToString()){
		
			for (int c = 0; c <= q_status->Length - 1; c++) {
				int temp_code = System::Int32::Parse(this->q_status[a_status]->ToStr()[2].ToString());

				if (temp_code == this->q_status[c]->code) {

					a_status = c;

					return this->q_status[a_status]->ToStr()[1].ToString();
				}
				else {
					if (c == q_status->Length - 1) {
						return "";
					}
				}
			}
		}
		else {
			return "";
		}
	}

		//returns the word to read
		public: System::String^ get_word() {
					return this->word;
				}

		//returns the actual status as ref struct
		public: status^ actual_status() {
					return this->q_status[a_status];
				}

		//make the translation of the word 
		public: System::String^ translate(System::String^ _word) {
					for (int c = 0; c < _word->Length; c++) {
						switch (this->q_status[a_status]->ToStr()[0] == _word[c]) {
							case true:
								this->word = this->word + this->q_status[a_status]->ToStr()[1];
								this->update(_word[c].ToString());
							
									break;
								default:
									break;
							}
						}
					return this->word;
				}

		//returns the integer acording to the actual status
		public: int GetStatus() {
			return this->a_status;
		}
	};

#pragma region CONSTRUCTORS

	Mealy::Mealy(int _q_states_n, bool _a_state, int _new_status) {

		switch (_a_state) {
			case true:
				srand(time(0));
				this->a_status = rand()% (_q_states_n);
				break;
			case false:
				this->a_status = _new_status;
				break;
			}
		this->q_status = gcnew cli::array<status^>(_q_states_n);

	}

	status::status(String^ _symbol, int _code) {
			symbols = gcnew cli::array<String^>(3);
			symbols[0] = _symbol[0].ToString();
			symbols[1] = _symbol[1].ToString();
			symbols[2] = _symbol[2].ToString();
			code = _code;
	}
#pragma endregion
}
//Writted by Fuzz