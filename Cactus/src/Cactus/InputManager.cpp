#include "cactus_pch.h"

#include "Cactus/InputManager.h"

namespace Cactus
{
	std::unordered_map<int, int> InputManager::keyMap;
	std::unordered_map<int, bool> InputManager::keyQueue;

	bool InputManager::KeyDown(int key)
	{
		if (keyMap.find(key) == keyMap.end())
		{
			return false;
		}

		return keyMap[key] == 1 || keyMap[key] == 2;
	}

	bool InputManager::KeyUp(int key)
	{
		if (keyMap.find(key) == keyMap.end())
		{
			return true;
		}

		return keyMap[key] == 0 || keyMap[key] == 3;
	}

	bool InputManager::KeyPressed(int key)
	{
		if (keyMap.find(key) == keyMap.end())
		{
			return false;
		}

		return keyMap[key] == 1;
	}

	bool InputManager::KeyReleased(int key)
	{
		if (keyMap.find(key) == keyMap.end())
		{
			return false;
		}

		return keyMap[key] == 3;
	}

	void InputManager::Update()
	{

		auto it = keyMap.begin();

		while (it != keyMap.end())
		{
			int keycode = it->first;
			int value = it->second;

			bool down = false;
			if (keyQueue.find(keycode) != keyQueue.end())
			{
				down = keyQueue[keycode];
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

			keyMap[keycode] = value;
		}
	}

	void InputManager::UpdateKey(int keycode, bool down)
	{
		keyQueue[keycode] = down;
	}
}