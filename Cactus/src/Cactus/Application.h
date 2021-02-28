#pragma once

#include "Core.h"

namespace Cactus {
	class CACTUS_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	//Client defined
	Application* CreateApplication();

}