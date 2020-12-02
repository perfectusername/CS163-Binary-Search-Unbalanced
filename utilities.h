/*
	utilities.h

	Utilities to support interface

	Author: Brooke Czerwinski
	Date:	10/17/2020
	Class:	CS163
	Program #3

*/

#ifndef UTILITIES_H
#define UTILITIES_H

const int MAX_CHAR = 256;

// Input Utilities
//
void takeInput(int& input, const char prompt[]);
void takeInput(float& input, const char prompt[]);
void takeInput(char& input, const char prompt[]);
void takeInput(char input[], const char prompt[]);

// Error Handling
//
void cinErrorCheck(bool& errorFlag);
void checkNext(bool& errorFlag);
void invalidEntry(const bool& errorFlag);
bool quitCheck(const char input[]);
bool quitCheck(const char& input);

#endif
