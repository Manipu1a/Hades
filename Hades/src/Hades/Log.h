#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Hades {
	class HADES_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }


	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;

	};
}


// Core log macros
#define HADES_CORE_TRACE(...)	::Hades::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define HADES_CORE_INFO(...)	::Hades::Log::GetCoreLogger()->info(__VA_ARGS__)
#define HADES_CORE_WARN(...)	::Hades::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define HADES_CORE_ERROR(...)	::Hades::Log::GetCoreLogger()->error(__VA_ARGS__)
#define HADES_CORE_FATAL(...)	::Hades::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define HADES_TRACE(...)		::Hades::Log::GetClientLogger()->trace(__VA_ARGS__)
#define HADES_INFO(...)			::Hades::Log::GetClientLogger()->info(__VA_ARGS__)
#define HADES_WARN(...)			::Hades::Log::GetClientLogger()->warn(__VA_ARGS__)
#define HADES_ERROR(...)		::Hades::Log::GetClientLogger()->error(__VA_ARGS__)
#define HADES_FATAL(...)		::Hades::Log::GetClientLogger()->fatal(__VA_ARGS__)

