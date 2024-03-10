#pragma once
#include "ElementBase.h"
#include <string>
#include <vector>

namespace CommandMenu
{
	class Tab
	{
	public:
		Tab(const std::string& name);
		void AddElement(ElementPtr element);
		void Display() const;
		void Navigate(int delta);
		void ChangeActiveElementValue(int delta);
		std::string GetName() const { return m_name; }

	private:
		std::string m_name;
		std::vector<ElementPtr> m_elements;
		size_t m_selectedElement;
	};
}
