#include "../include/SliderInt.h"
#include <iostream>

namespace CommandMenu
{
	SliderInt::SliderInt(const std::string& name, int value, int min, int max, int step)
		: m_name(name), m_value(value), m_min(min), m_max(max), m_step(step)
	{
	}

	void SliderInt::Display(bool selected) const
	{
		std::cout << (selected ? "> " : "   ") << m_name << ": " << m_value << '\n';
	}

	void SliderInt::ChangeValue(int delta)
	{
		if (delta > 0 && m_value + m_step <= m_max)
		{
			m_value += m_step;
		}
		else if (delta < 0 && m_value - m_step >= m_min)
		{
			m_value -= m_step;
		}
	}
}
