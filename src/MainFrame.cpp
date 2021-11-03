#include"MainFrame.h"

bool MainFrame::responseEntryLine(Terminal & object)
{
	if (object.getStringNumber() < _MAX_STRING)
	{
		__int64 downTime_buffer = this->_prev_time - object.getTerminalGlobalTime();

		if (downTime_buffer > NULL)
		{
			object.setDownTime(object.getDownTime() + downTime_buffer);
		}

		if (this->_prev_time < object.getTerminalGlobalTime())
			this->_prev_time = object.getTerminalGlobalTime() + 3;
		else
			this->_prev_time += 3;

		this->_mainframe_busy_time += 3;
		this->_mainframe_global_time = _prev_time;
		object.setTerminalGlobalTime(object.getTerminalGlobalTime() + 3);

		object.coutResultSetLine();
	}
	else
	{
		__int64 downTime_buffer = this->_prev_time - object.getTerminalGlobalTime();

		if (downTime_buffer > NULL)
		{
			object.setDownTime(object.getDownTime() + downTime_buffer);
		}

		__int32 buffer_time = 7 + rand() % 6;

		if (this->_prev_time < object.getTerminalGlobalTime())
			this->_prev_time = object.getTerminalGlobalTime() + buffer_time;
		else
			this->_prev_time += buffer_time;

		this->_mainframe_busy_time += buffer_time;
		this->_mainframe_global_time = _prev_time;
		object.setTerminalGlobalTime(object.getTerminalGlobalTime() + buffer_time);

		object.analysisOfTheResult();
	}

	return FALSE;
}