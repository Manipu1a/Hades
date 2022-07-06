#pragma once

#ifdef HADES_PLATFORM_WINDOWS
	#ifdef HADES_BUILD_DLL
		#define HADES_API __declspec(dllexport)
	#else 
		#define HADES_API __declspec(dllimport)
	#endif
#else 
	#error Hades only support Windows!
#endif

#define BIT(x) (1 << x)