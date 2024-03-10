#pragma once
#include "Tab.h"
#include <memory>
#include <vector>

namespace CommandMenu
{
	class Menu
	{
	public:
		Menu();
		void AddTab(std::unique_ptr<Tab> tab);
		void Display() const;
		void Navigate(int delta);
		void ProcessInput();

	private:
		std::vector<std::unique_ptr<Tab>> m_tabs;
		size_t m_selectedTab;
	};
}
