#pragma once
#include "ElementBase.h"
#include <string>

namespace CommandMenu
{
	class Toggle : public ElementBase
	{
	public:
		Toggle(const std::string& name, bool* value);
		Toggle(const std::string& name, bool value);
		~Toggle();
		
		void Display(bool selected) const override;
		void ChangeValue(int delta) override;
		
	private:
		std::string m_name;
		bool* m_value;
		bool m_shouldDeleteValue;
	};
}
