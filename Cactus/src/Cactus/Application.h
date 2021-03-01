#pragma once

#include "Cactus/Core.h"

#include "Cactus/Window.h"
#include "Cactus/LayerStack.h"
#include "Cactus/Events/Event.h"
#include "Cactus/Events/ApplicationEvent.h"

namespace Cactus {
	class CACTUS_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

	private:
		bool OnWindowClose(WindowCloseEvent& e);
		std::unique_ptr<Window> window;

		bool running = false;
		LayerStack layerStack;
	};

	//Client defined
	Application* CreateApplication();

}