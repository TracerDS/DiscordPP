#include <misc/utils.hpp>
#include <cstdarg>

namespace Utils {
    std::string JoinHTTPHeader(
		const std::string key,
		const std::string value
	) noexcept {
		return key + ": " + value;
	}

    std::string FormatString(const char* format, ...) noexcept {
		std::va_list args;
		va_start(args, format);
		auto size = std::vsnprintf(0, 0, format, args);
		va_end(args);

		std::string out(size, 0);
		va_start(args, format);
		std::vsnprintf(out.data(), size + 1, format, args);
		va_end(args);

		return out;
	}
}