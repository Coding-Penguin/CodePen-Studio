#pragma once
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace CodePen {

	class Log
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

// Core Log Macros
#define PS_CORE_DEBUG(...)		::CodePen::Log::GetCoreLogger()->debug(__VA_ARGS__)
#define PS_CORE_TRACE(...)		::CodePen::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define PS_CORE_INFO(...)		::CodePen::Log::GetCoreLogger()->info(__VA_ARGS__)
#define PS_CORE_WARN(...)		::CodePen::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define PS_CORE_ERROR(...)		::CodePen::Log::GetCoreLogger()->error(__VA_ARGS__)
#define PS_CORE_FATAL(...)		::CodePen::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client Log Macros
#define PS_DEBUG(...)		::CodePen::Log::GetClientLogger()->debug(__VA_ARGS__)
#define PS_TRACE(...)		::CodePen::Log::GetClientLogger()->trace(__VA_ARGS__)
#define PS_INFO(...)		::CodePen::Log::GetClientLogger()->info(__VA_ARGS__)
#define PS_WARN(...)		::CodePen::Log::GetClientLogger()->warn(__VA_ARGS__)
#define PS_ERROR(...)		::CodePen::Log::GetClientLogger()->error(__VA_ARGS__)
#define PS_FATAL(...)		::CodePen::Log::GetClientLogger()->critical(__VA_ARGS__)