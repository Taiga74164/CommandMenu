#include "../include/Toggle.h"
#include <iostream>
#include <Windows.h>

namespace CommandMenu
{
	Toggle::Toggle(const std::string& name, bool* value)
		: m_name(name), m_value(value), m_shouldDeleteValue(false)
	{
	}

	Toggle::Toggle(const std::string& name, bool value)
		: m_name(name), m_value(new bool(value)), m_shouldDeleteValue(true)
	{
	}

	Toggle::~Toggle()
	{
		if (m_shouldDeleteValue)
		{
			delete m_value;
		}
	}

	void Toggle::Display(bool selected) const
	{
		const auto hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		std::cout << (selected ? "> " : "   ") << m_name << ": ";

		if (*m_value)
		{
			SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			std::cout << "ON";
		}
		else
		{
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
			std::cout << "OFF";
		}

		SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		std::cout << '\n';
	}

	void Toggle::ChangeValue(int delta)
	{
		*m_value = !*m_value;
	}
}