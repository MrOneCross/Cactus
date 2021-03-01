#pragma once

#include "Cactus/Core.h"
#include "Cactus/Events/Event.h"

#include <unordered_map>
namespace Cactus
{
	
	class CACTUS_API Input
	{
	public:
		static bool KeyDown(int key);
		static bool KeyUp(int key);
		static bool KeyPressed(int key);
		static bool KeyReleased(int key);
		
		static bool MouseButtonDown(int button);
		static bool MouseButtonUp(int button);
		static bool MouseButtonPressed(int button);
		static bool MouseButtonReleased(int button);

		static inline float GetMouseX() { return mouseX; }
		static inline float GetMouseY() { return mouseY; }



		static void OnEvent(Event& event);

		//Actually update all values like pressed and released
		static void Update();
		
	private:
		static std::unordered_map<int, bool> keyQueue;
		static std::unordered_map<int, int> keyMap;

		static std::unordered_map<int, bool> mouseQueue;
		static std::unordered_map<int, int> mouseMap;

		static float mouseX;
		static float mouseY;
		Input() {};
		~Input() {};

		static void UpdateMap(std::unordered_map<int, bool>* queue, std::unordered_map<int, int>* map);
		
	};
	
}