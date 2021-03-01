#include <Cactus.h>

class ExampleLayer : public Cactus::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		if (Cactus::Input::KeyDown(65))
		{
			CACTUS_INFO("Moving left!");
		}
		else
		{
			CACTUS_INFO("Standing still!");
		}
	}

	void OnEvent(Cactus::Event& event) override
	{
		//CACTUS_TRACE("{0}",event);
	}

};

class Sandbox : public Cactus::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new Cactus::ImGuiLayer());
		PushOverlay(new Cactus::InputLayer());
	}

	~Sandbox()
	{
	}
};

Cactus::Application* Cactus::CreateApplication() {
	return new Sandbox();
}