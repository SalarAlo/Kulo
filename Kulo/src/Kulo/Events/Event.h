#pragma once

#include "Kulo.h"

#include <string>
#include <functional>

namespace Kulo {
	enum class EventType {
		None,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	enum EvenCategory {
		None = 0,
		EventCategoryApplication   = BIT(0),
		EventCategoryInput         = BIT(1),
		EventCategoryKeyboard      = BIT(2),
		EventCategoryMouse         = BIT(3),
		EventCategoryMouseButton   = BIT(4),
	};

#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::##type }\
				virtual EventType GetEventType() const override { return GetStaticType(); }\
				virtual const char* GetName() const override { return #type; }

}
