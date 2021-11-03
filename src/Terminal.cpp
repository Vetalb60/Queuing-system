#include"Terminal.h"

bool Terminal::taskLineSet()
{
	__int64 buffer = 5 + rand() % 10;
	this->_terminal_busy_time += buffer;
	this->_terminal_global_time += buffer;
	this->incStringNumber();

	return FALSE;
}

bool Terminal::coutResultSetLine()
{
	this->_terminal_busy_time += 5;
	this->_terminal_global_time += 5;

	return FALSE;
}

bool Terminal::analysisOfTheResult()
{
	this->_terminal_busy_time += 38;
	this->_terminal_global_time += 38;

	return FALSE;
}
