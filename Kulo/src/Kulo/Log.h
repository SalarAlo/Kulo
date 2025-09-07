#pragma once

#include <memory>

#include <spdlog/spdlog.h>

#include "Core.h"

namespace Kulo {
	class KULO_API Log {
	public:
		static void Init();
		static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

		Log();
		~Log();
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Core log macros
#define KL_CORE_FATAL(...)   ::Kulo::Log::GetCoreLogger()->fatal(__VA_ARGS__)
#define KL_CORE_ERROR(...)   ::Kulo::Log::GetCoreLogger()->error(__VA_ARGS__)
#define KL_CORE_WARN(...)    ::Kulo::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define KL_CORE_INFO(...)    ::Kulo::Log::GetCoreLogger()->info(__VA_ARGS__)
#define KL_CORE_TRACE(...)   ::Kulo::Log::GetCoreLogger()->trace(__VA_ARGS__)

// Client log macros
#define KL_FATAL(...)   ::Kulo::Log::GetClientLogger()->fatal(__VA_ARGS__)
#define KL_ERROR(...)   ::Kulo::Log::GetClientLogger()->error(__VA_ARGS__)
#define KL_WARN(...)    ::Kulo::Log::GetClientLogger()->warn(__VA_ARGS__)
#define KL_INFO(...)    ::Kulo::Log::GetClientLogger()->info(__VA_ARGS__)
#define KL_TRACE(...)   ::Kulo::Log::GetClientLogger()->trace(__VA_ARGS__)
