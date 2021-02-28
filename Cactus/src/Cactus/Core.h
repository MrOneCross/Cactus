#pragma once

#ifdef CACTUS_PLATFORM_WINDOWS
	#ifdef CACTUS_BUILD_DLL
		#define CACTUS_API __declspec(dllexport)
	#else
		#define CACTUS_API __declspec(dllimport)
	#endif
#else
	#error Cactus only supports Windows!
#endif


