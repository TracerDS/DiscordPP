#pragma once

#include <string>

namespace Utils {
	std::string JoinHTTPHeader (
		const std::string key,
		const std::string value
	) noexcept;

	std::string FormatString(const char* format, ...) noexcept;

	template <typename Enumeration>
	constexpr auto EnumToValue(const Enumeration value) noexcept
		-> typename std::underlying_type<Enumeration>::type
	{
		return static_cast<typename std::underlying_type<Enumeration>::type>(value);
	}

	template <typename Enumeration>
	constexpr Enumeration ValueToEnum(const std::int64_t value) noexcept
	{
		return static_cast<Enumeration>(value);
	}
}