#pragma once
#include<iostream>

#include"Terminal.h"

class MainFrame
{
public:
	MainFrame()
	{
		this->_mainframe_busy_time	= NULL;
		this->_is_busy				= FALSE;
		this->_prev_time			= NULL;
		this->setMainframeGlobalTime(NULL);
	}

public:
	__int64 getMainframeBusyTime() { return this->_mainframe_busy_time; }
	__int64 getMainframeGlobalTime() { return this->_mainframe_global_time; }
	__int64 getPrevTime() { return this->_prev_time; }
	void	setMainframeGlobalTime(__int64 time) { this->_mainframe_global_time = time; }
public:
	bool  responseEntryLine(Terminal& object);
private:
	__int64		_mainframe_global_time;
	__int64		_mainframe_busy_time;
	__int64		_prev_time;
	bool		_is_busy;
};
