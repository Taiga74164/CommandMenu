#pragma once
#include "ElementBase.h"
#include <string>

namespace CommandMenu
{
	class SliderFloat : public ElementBase
	{
	public:
		SliderFloat(const std::string& name, float* value, float min, float max, float step);
		void Display(bool selected) const override;
		void ChangeValue(int delta) override;
		
	private:
		std::string m_name;
		float* m_value;
		float m_min, m_max, m_step;
	};
}
