#include<iostream>
#include<algorithm>
#include<random>
#include<cmath>
#include<ctime>
#include<vector>
#include<string>

#include"MainFrame.h"
#include"Terminal.h"

using std::vector;

class MainFrame;
class Terminal;

Terminal& minTerminalGlobalTime(vector<Terminal> &terminals);
bool globalTimeIsLess(vector<Terminal> &terminals);

MainFrame __mainframe__;

int main()
{
	srand(time(NULL));

	int counter		= NULL;
	
	vector<Terminal> vec_terminals;

	for (size_t i = 0; i < _TERMINAL_NUMBER; i++)
	{
		vec_terminals.push_back(Terminal());
		vec_terminals.back().taskLineSet();
	}

	while (__mainframe__.getMainframeGlobalTime() <= _SIX_HOURS &&
		   __mainframe__.getMainframeBusyTime()   <= _SIX_HOURS	&&
		  globalTimeIsLess(vec_terminals))
	{
		Terminal *_term_buffer = &minTerminalGlobalTime(vec_terminals);

		__mainframe__.responseEntryLine(*_term_buffer);
		_term_buffer->taskLineSet();
	}

	std::cout << "\n\t\tLadidadida.cpp\t\t" << std::endl;
	std::cout << "\n=============TERMINAL BUSY TIME=============\n" << std::endl;
	for (auto iter : vec_terminals)
	{
		std::cout << "\tTerminal "<< std::to_string(counter) +": " << iter.getTerminalBusyTime() << " sec" << std::endl;
		counter++;
	}

	counter = int(NULL);
	std::cout << "\n=============TERMINAL LOAD FACTOR=============\n" << std::endl;
	for (auto iter : vec_terminals)
	{
		std::cout << "\tTerminal " << std::to_string(counter) + ": " << (double_t)iter.getTerminalBusyTime() / _SIX_HOURS  << std::endl;
		counter++;
	}

	counter = int(NULL);
	std::cout << "\n=============TERMINAL DOWN TIME=============\n" << std::endl;
	for (auto iter : vec_terminals)
	{
		std::cout << "\tTerminal " << std::to_string(counter) + ": " << iter.getDownTime() << " sec" << std::endl;
		counter++;
	}
	
	std::cout << "\n=============MAINFRAME BUSY TIME============\n" << std::endl;
	std::cout << "\t\t" << __mainframe__.getMainframeBusyTime() << " sec" << std::endl;
	
	counter = int(NULL);
	std::cout << "\n======PROBABILITY OF TERMINAL DOWNTIME======\n" << std::endl;

	double_t probability	= NULL;
	double_t middle_val		= NULL;
	double_t math_exp		= NULL;

	for (auto iter : vec_terminals)
	{
		probability = (double_t)iter.getDownTime() / (_SIX_HOURS - iter.getTerminalBusyTime());
		math_exp += (double_t)iter.getDownTime() * probability;
		middle_val += probability;
		std::cout << "\tTerminal " << std::to_string(counter) + ": " << probability << std::endl;
		counter++;
	}

	middle_val /= _TERMINAL_NUMBER;

	std::cout << "\tMiddle value:" << middle_val << std::endl;
	std::cout << "   Mathematical Expectation:" << math_exp << std::endl;

	std::cout << "\n============COMPUTER LOAD FACTOR============\n" << std::endl;
	std::cout << "\t\t" << (double)__mainframe__.getMainframeBusyTime() / _SIX_HOURS << std::endl;
	return 0;
}

Terminal& minTerminalGlobalTime(vector<Terminal> &terminals)
{
	__int64 min_value			 = terminals.at(NULL).getTerminalGlobalTime();
	__int64 counter				 = NULL;
	__int64 index_minGT_terminal = NULL;

	for (auto iter : terminals)
	{
		if (min_value > iter.getTerminalGlobalTime())
		{
			index_minGT_terminal = counter;
			min_value = iter.getTerminalGlobalTime();
		}
		counter++;
	}

	return terminals.at(index_minGT_terminal);
}

bool globalTimeIsLess(vector<Terminal>& terminals)
{
	for (auto iter : terminals)
	{
		if (iter.getTerminalGlobalTime() >= _SIX_HOURS && iter.getTerminalBusyTime() >= _SIX_HOURS)
		{
			return FALSE;
		}

		if (iter.getDownTime() >= _SIX_HOURS && iter.getDownTime() >= _SIX_HOURS)
		{
			return FALSE;
		}

		if (_SIX_HOURS - iter.getTerminalBusyTime() - 50 < iter.getDownTime())
		{
			return FALSE;
		}
	}

	return TRUE;
}
