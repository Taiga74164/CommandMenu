#include "../include/SliderFloat.h"
#include <iostream>

namespace CommandMenu
{
	SliderFloat::SliderFloat(const std::string& name, float* value, float min, float max, float step)
		: m_name(name), m_value(value), m_min(min), m_max(max), m_step(step)
	{
	}

	void SliderFloat::Display(bool selected) const
	{
		std::cout << (selected ? "> " : "   ") << m_name << ": " << *m_value << '\n';
	}

	void SliderFloat::ChangeValue(int delta)
	{
		if (delta > 0 && *m_value + m_step <= m_max)
		{
			*m_value += m_step;
		}
		else if (delta < 0 && *m_value - m_step >= m_min)
		{
			*m_value -= m_step;
		}
	}
}
