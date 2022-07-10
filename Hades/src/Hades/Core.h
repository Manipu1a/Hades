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


#ifdef HADES_ENABLE_ASSERTS
	#define HADES_ASSERT(x, ...) { if(!(x)) { HADES_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); }}
	#define HADES_CORE_ASSERT(x, ...) { if(!(x)) { HADES_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); }}
#else
	#define HADES_ASSERT(x, ...)
	#define HADES_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)