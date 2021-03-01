#pragma once

#include <unordered_map>

namespace Cactus
{
	
	class CACTUS_API InputManager
	{
	public:
		static void Init();
		static void Destroy();
		static bool KeyDown(int key);
		static bool KeyUp(int key);
		static bool KeyPressed(int key);
		static bool KeyReleased(int key);

		//Queue key change to use it in update
		static void UpdateKey(int key, bool down);

		//Actually update all values like pressed and released
		static void Update();
	private:
		InputManager() {};
		~InputManager() {};
		//key , down/up
		static std::unordered_map<int, bool> keyQueue;

		//key , state (0=up,1=keypressed,2=down,3=keyreleased)
		static std::unordered_map<int, int> keyMap;
	};
	
}