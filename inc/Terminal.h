#pragma once
#include<iostream>

#define TRUE				true
#define FALSE				false

#define _SIX_HOURS			21600
#define _MAX_STRING			10
#define _TERMINAL_NUMBER	3

class Terminal
{
public:
	Terminal()
	{
		this->_downtime				= NULL;
		this->_terminal_busy_time	= NULL;
		this->_is_busy				= FALSE;
		this->_string_counter		= NULL;
		this->setTerminalGlobalTime(NULL);
	}

public:
	__int64 getTerminalGlobalTime() { return this->_terminal_global_time; }
	void	setTerminalGlobalTime(__int64 time) { this->_terminal_global_time = time; }
	__int64 getTerminalBusyTime() { return this->_terminal_busy_time; }
	__int64 getDownTime() { return this->_downtime; }
	void	setDownTime(__int64 time) { this->_downtime = time; }
	__int32 getStringNumber() { return this->_string_counter; }
	void	setStringNumber(__int32 value) { this->_string_counter = value; }
	void	incStringNumber() { this->_string_counter++; }
public:
	bool  taskLineSet();
	bool  coutResultSetLine();
	bool  analysisOfTheResult();
private:
	__int64		_terminal_global_time;
	__int64		_terminal_busy_time;
	__int64		_downtime;
	bool		_is_busy;
	__int32		_string_counter;
};