#include "cactus_pch.h"

#include "Input.h"
#include <Cactus\Events\KeyEvent.h>
#include <Cactus\Events\MouseEvent.h>
namespace Cactus
{
	std::unordered_map<int, int> Input::keyMap;
	std::unordered_map<int, bool> Input::keyQueue;

	std::unordered_map<int, int> Input::mouseMap;
	std::unordered_map<int, bool> Input::mouseQueue;

	float Input::mouseX = 0.0f;
	float Input::mouseY = 0.0f;

	bool Input::KeyDown(int key)
	{
		if (keyMap.find(key) == keyMap.end())
		{
			return false;
		}

		return keyMap[key] == 1 || keyMap[key] == 2;
	}

	bool Input::KeyUp(int key)
	{
		if (keyMap.find(key) == keyMap.end())
		{
			return true;
		}

		return keyMap[key] == 0 || keyMap[key] == 3;
	}

	bool Input::KeyPressed(int key)
	{
		if (keyMap.find(key) == keyMap.end())
		{
			return false;
		}

		return keyMap[key] == 1;
	}

	bool Input::KeyReleased(int key)
	{
		if (keyMap.find(key) == keyMap.end())
		{
			return false;
		}

		return keyMap[key] == 3;
	}

	bool Input::MouseButtonDown(int button)
	{
		if (mouseMap.find(button) == mouseMap.end())
		{
			return false;
		}

		return mouseMap[button] == 1 || mouseMap[button] == 2;
	}

	bool Input::MouseButtonUp(int button)
	{
		if (mouseMap.find(button) == mouseMap.end())
		{
			return true;
		}

		return mouseMap[button] == 0 || mouseMap[button] == 3;
	}

	bool Input::MouseButtonPressed(int button)
	{
		if (mouseMap.find(button) == mouseMap.end())
		{
			return false;
		}

		return mouseMap[button] == 1;
	}

	bool Input::MouseButtonReleased(int button)
	{
		if (mouseMap.find(button) == mouseMap.end())
		{
			return false;
		}

		return mouseMap[button] == 3;
	}


	void Input::UpdateMap(std::unordered_map<int, bool>* queueptr, std::unordered_map<int, int>* mapptr)
	{
		auto& queue = *queueptr;
		auto& map = *mapptr;

		for (auto& it : map) {
			int code = it.first;
			int value = it.second;

			bool down = false;
			if (queue.find(code) != queue.end())
			{
				down = queue[code];
			}

			//key , state (0=up,1=keypressed,2=down,3=keyreleased)

			switch (value)
			{
			case 0:
			{
				value = down ? 1 : value;
				break;
			}
			case 1:
			{
				value = down ? 2 : 3;
				break;
			}
			case 2:
			{
				value = down ? 2 : 3;
				break;
			}
			case 3:
			{
				value = down ? 1 : 0;
				break;
			}
			}

			map[code] = value;
		}
	}

	void Input::Update()
	{
		UpdateMap(&keyQueue, &keyMap);
		UpdateMap(&mouseQueue, &mouseMap);
	}


	void Input::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);

		dispatcher.Dispatch<KeyPressedEvent>([](KeyPressedEvent& e)
			{
				keyQueue[e.GetKeyCode()] = true;

				if (keyMap.find(e.GetKeyCode()) == keyMap.end())
				{
					keyMap[e.GetKeyCode()] = 0;
				}
				return false;
			});
		dispatcher.Dispatch<KeyReleasedEvent>([](KeyReleasedEvent& e)
			{
				keyQueue[e.GetKeyCode()] = false;

				if (keyMap.find(e.GetKeyCode()) == keyMap.end())
				{
					keyMap[e.GetKeyCode()] = 0;
				}
				return false;
			});
		dispatcher.Dispatch<MouseMovedEvent>([](MouseMovedEvent& e)
			{
				mouseX = e.GetX();
				mouseY = e.GetY();

				return false;
			});
		dispatcher.Dispatch<MouseButtonPressedEvent>([](MouseButtonPressedEvent& e)
			{
				mouseQueue[e.GetMouseButton()] = true;

				if (mouseMap.find(e.GetMouseButton()) == mouseMap.end())
				{
					mouseMap[e.GetMouseButton()] = 0;
				}
				return false;
			});
		dispatcher.Dispatch<MouseButtonReleasedEvent>([](MouseButtonReleasedEvent& e)
			{
				mouseQueue[e.GetMouseButton()] = false;

				if (mouseMap.find(e.GetMouseButton()) == mouseMap.end())
				{
					mouseMap[e.GetMouseButton()] = 0;
				}
				return false;
			});
	}
}