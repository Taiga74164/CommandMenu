#pragma once
#include "ElementBase.h"
#include <string>

namespace CommandMenu
{
	class Text : public ElementBase
	{
	public:
		Text(const std::string& text);
		void Display(bool selected) const override;
		void ChangeValue(int delta) override;
		
	private:
		std::string m_text;
	};
}
