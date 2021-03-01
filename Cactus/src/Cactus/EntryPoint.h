#pragma once


#ifdef CACTUS_PLATFORM_WINDOWS

extern Cactus::Application* Cactus::CreateApplication();

int main(int argc, char** argv)
{
	
	Cactus::Log::Init();

	CACTUS_CORE_INFO("Initializing Engine...");

	auto app = Cactus::CreateApplication();
	app->Run();
	delete app;
}

#endif
