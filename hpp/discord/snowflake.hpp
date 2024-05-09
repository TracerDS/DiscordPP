#pragma once

#include <cstdint>
#include <string>
#include <fstream>

namespace DiscordPP {
	class Snowflake {
	protected:
		std::uint64_t m_data;
	public:
		Snowflake(const std::uint64_t rawData = 0) noexcept;
		Snowflake(const int rawData) noexcept;
		Snowflake(const char string[8]) noexcept;

		Snowflake& operator=(const std::uint64_t rawData) noexcept;
		operator bool() const noexcept;

		bool operator==(const std::uint64_t data) const noexcept;
		bool operator==(const Snowflake data) const noexcept;
		bool operator==(const int data) const noexcept;
		bool operator!=(const std::uint64_t data) const noexcept;
		bool operator!=(const Snowflake data) const noexcept;
		bool operator!=(const int data) const noexcept;

		std::uint64_t GetTimestamp() const noexcept;
		std::uint8_t GetWorkerID() const noexcept;
		std::uint8_t GetProcessID() const noexcept;
		std::uint16_t IncrementNumber() const noexcept;

		std::uint64_t GetData() const noexcept;
		operator std::uint64_t() const noexcept;

		std::string ToString() const noexcept;
		operator std::string() const noexcept;

		friend std::ostream& operator<<(
			std::ostream& stream,
			const Snowflake id
		) noexcept {
			return stream << id.GetData();
		}
	};
}
