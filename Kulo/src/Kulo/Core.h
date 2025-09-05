#pragma once

#ifdef KL_PLATFORM_WIN
	#ifdef KL_BUILD_DLL
		#define KULO_API __declspec(dllexport)
	#else
		#define KULO_API __declspec(dllimport)
	#endif
#else
	#error Your platform isnt specified!
#endif