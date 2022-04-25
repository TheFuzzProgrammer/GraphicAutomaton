#pragma once
#include <stdlib.h>

namespace Conversions {

	int FromCharToInteger(char _char) {
		/*
		Why pointers:

		-Bc this is C++

		-The pointer points to an addres on memory 
		 where is allocated _char

		-atoi(char) from stdlib can convert the 
		 value allocated on the mem 
		 address of the pointer to an integer 

		-is easier, and uses less resources

		-And because this is C++
		*/
		char* pointer = &_char;
		int lambda = atoi(pointer);
		return lambda;
	} 
}