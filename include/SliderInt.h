#pragma once
#include "ElementBase.h"
#include <string>

namespace CommandMenu
{
	class SliderInt : public ElementBase
	{
	public:
		SliderInt(const std::string& name, int value, int min, int max, int step);
		void Display(bool selected) const override;
		void ChangeValue(int delta) override;
		
	private:
		std::string m_name;
		int m_value, m_min, m_max, m_step;
	};
}
