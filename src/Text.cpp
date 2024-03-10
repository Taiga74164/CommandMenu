#include "../include/Text.h"
#include <iostream>

namespace CommandMenu
{
	Text::Text(const std::string& text)
		: m_text(text)
	{
	}

	void Text::Display(bool selected) const
	{
		std::cout << (selected ? "> " : "  ") << m_text << '\n';
	}

	void Text::ChangeValue(int delta)
	{
	}
}
