#include "cactus_pch.h"

#include "Cactus/Events/Event.h"
#include "Cactus/Input/InputLayer.h"
#include "Cactus/Input/Input.h"
#include "Cactus/Layer.h"

namespace Cactus
{
	
	InputLayer::InputLayer()
		: Layer("Input") {}

	InputLayer::~InputLayer()
	{

	}


	void InputLayer::OnUpdate()
	{
		Input::Update();
	}
	
	void InputLayer::OnEvent(Cactus::Event& event)
	{
		Input::OnEvent(event);
	}
	
}