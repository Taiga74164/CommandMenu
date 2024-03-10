#pragma once
#include <memory>

namespace CommandMenu
{
	class ElementBase
	{
	public:
		virtual void Display(bool selected) const = 0;
		virtual void ChangeValue(int delta) = 0;
		virtual ~ElementBase() = default;
	};

	using ElementPtr = std::unique_ptr<ElementBase>;
}
