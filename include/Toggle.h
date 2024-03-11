#pragma once
#include "ElementBase.h"
#include <string>
#include <functional>

namespace CommandMenu
{
	class Toggle : public ElementBase
	{
	public:
		Toggle(const std::string& name, std::function<void(bool)> callback);
		void Display(bool selected) const override;
		void ChangeValue(int delta) override;
		
	private:
		std::string m_name;
		bool m_value;
		std::function<void(bool)> m_callback;
	};
}
