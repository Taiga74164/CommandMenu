#include "../include/Menu.h"
#include <iostream>
#include <Windows.h>

enum {
	COLOR_BLACK = 0,
	COLOR_DARK_BLUE = 1,
	COLOR_DARK_GREEN = 2,
	COLOR_LIGHT_BLUE = 3,
	COLOR_DARK_RED = 4,
	COLOR_MAGENTA = 5,
	COLOR_ORANGE = 6,
	COLOR_LIGHT_GRAY = 7,
	COLOR_GRAY = 8,
	COLOR_BLUE = 9,
	COLOR_GREEN = 10,
	COLOR_CYAN = 11,
	COLOR_RED = 12,
	COLOR_PINK = 13,
	COLOR_YELLOW = 14,
	COLOR_WHITE = 15
};

namespace CommandMenu
{
	Menu::Menu() = default;

	void Menu::AddTab(std::unique_ptr<Tab> tab)
	{
		m_tabs.push_back(std::move(tab));
	}

	void Menu::Display() const
	{
		if (!m_tabs.empty())
		{
			for (auto i =0; i < m_tabs.size(); i++)
			{
				if (i == m_selectedTab)
				{
					// Set the highlight color.
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), COLOR_GREEN);
					// Print the selected tab name.
					std::cout << "> " << m_tabs[i]->GetName() << " ";
					// Set the default color.
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), COLOR_LIGHT_GRAY);
				}
				else
				{
					std::cout << "  " << m_tabs[i]->GetName() << " ";
				}
			}

			std::cout << std::endl << std::endl;
			if (m_selectedTab < m_tabs.size())
				m_tabs[m_selectedTab]->Display();
		}
	}

	void Menu::Navigate(int delta)
	{
		if (delta > 0)
		{
			m_selectedTab = (m_selectedTab + 1) % m_tabs.size();
		}
		else
		{
			m_selectedTab = (m_selectedTab + m_tabs.size() - 1) % m_tabs.size();
		}
	}

	void Menu::ProcessInput()
	{
		const auto consoleWindow = GetConsoleWindow();
		const auto foregroundWindow = GetForegroundWindow();

		// Receive input only if the console window is focused and there are tabs to display.
		if (consoleWindow == foregroundWindow && !m_tabs.empty())
		{
			if (GetAsyncKeyState(VK_UP) & 0x8000)
				m_tabs[m_selectedTab]->Navigate(-1);
			else if (GetAsyncKeyState(VK_DOWN) & 0x8000)
				m_tabs[m_selectedTab]->Navigate(1);
			else if (GetAsyncKeyState(VK_LEFT) & 0x8000)
				m_tabs[m_selectedTab]->ChangeActiveElementValue(-1); 
			else if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
				m_tabs[m_selectedTab]->ChangeActiveElementValue(1);
			else if (GetAsyncKeyState(VK_TAB) & 0x8000)
				Navigate(1);

			system("cls");
			Display();
			Sleep(100);
		}
	}
}