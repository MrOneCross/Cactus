#pragma once

#include "cactus_pch.h"
#include "Cactus/Events/Event.h"

namespace Cactus 
{
	class CACTUS_API KeyEvent : public Event
	{
	public:
		inline int GetKeyCode() const { return keyCode; }

		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
	protected:
		KeyEvent(int keycode) : keyCode(keycode) {}
		int keyCode;
	};



	class CACTUS_API KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(int keycode, int repeatCount)
			: KeyEvent(keycode), repeatCount(repeatCount) {}

		inline int GetRepeatCount() const { return repeatCount; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyPressedEvent: " << keyCode << " (" << repeatCount << ")";
			return ss.str();
		}
		
		EVENT_CLASS_TYPE(KeyPressed)
	private:
		int repeatCount;
	};



	class CACTUS_API KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(int keycode)
			: KeyEvent(keycode) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyReleasedEvent: " << keyCode;
			return ss.str();
		}

		//Generate basic stuff
		EVENT_CLASS_TYPE(KeyReleased)
	};
}