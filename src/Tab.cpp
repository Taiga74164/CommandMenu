#include "../include/Tab.h"
#include <iostream>

namespace CommandMenu
{
	Tab::Tab(const std::string& name)
		: m_name(name)
	{
	}

	void Tab::AddElement(ElementPtr element)
	{
		m_elements.push_back(std::move(element));
	}

	void Tab::Display() const
	{
		for (size_t i = 0; i < m_elements.size(); ++i)
		{
			m_elements[i]->Display(i == m_selectedElement);
		}
	}

	void Tab::Navigate(int delta)
	{
		if (delta > 0)
		{
			m_selectedElement = (m_selectedElement + 1) % m_elements.size();
		}
		else
		{
			m_selectedElement = (m_selectedElement + m_elements.size() - 1) % m_elements.size();
		}
	}

	void Tab::ChangeActiveElementValue(int delta)
	{
		if (!m_elements.empty())
		{
			m_elements[m_selectedElement]->ChangeValue(delta);
		}
	}
}
