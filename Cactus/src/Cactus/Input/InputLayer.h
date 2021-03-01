#pragma once

#include "Cactus/Layer.h"
#include "Cactus/Events/KeyEvent.h"

namespace Cactus
{
	class CACTUS_API InputLayer : public Layer
	{
	public:
		InputLayer();
		~InputLayer();
		void OnUpdate();
		void OnEvent(Event& event);
	};

	/*
	class CACTUS_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		void OnAttach();
		void OnDetach();
		void OnUpdate();
		void OnEvent(Event& event);

	private:
		bool OnMouseButtonPressedEvent(MouseButtonPressedEvent& e);
		bool OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& e);
		bool OnMouseMovedEvent(MouseMovedEvent& e);
		bool OnMouseScrolledEvent(MouseScrolledEvent& e);

		bool OnKeyPressedEvent(KeyPressedEvent& e);
		bool OnKeyReleasedEvent(KeyReleasedEvent& e);
		bool OnKeyTypedEvent(KeyTypedEvent& e);
		bool OnWindowResizedEvent(WindowResizeEvent& e);

		float time = 0.0f;
	};*/
}


