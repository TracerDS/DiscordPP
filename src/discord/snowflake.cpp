#include <discord/snowflake.hpp>
#include <utils.hpp>

namespace DiscordPP {
    Snowflake::Snowflake(const std::uint64_t rawData) noexcept
        : m_data(rawData) {}

    Snowflake::Snowflake(const int rawData) noexcept
        : m_data(static_cast<std::uint64_t>(rawData)) {}

    Snowflake::Snowflake(const char string[8]) noexcept
        : m_data(std::stoull(string)) {}

    Snowflake& Snowflake::operator=(const std::uint64_t rawData) noexcept {
        m_data = rawData;
        return *this;
    }
    Snowflake::operator bool() const noexcept {
        return operator!=(0);
    }

    bool Snowflake::operator==(const std::uint64_t data) const noexcept {
        return m_data == data;
    }
    bool Snowflake::operator==(const Snowflake data) const noexcept {
        return m_data == data.m_data;
    }
    bool Snowflake::operator==(const int data) const noexcept {
        return m_data == static_cast<std::uint64_t>(data);
    }
    bool Snowflake::operator!=(const std::uint64_t data) const noexcept {
        return !operator==(data);
    }
    bool Snowflake::operator!=(const Snowflake data) const noexcept {
        return !operator==(data);
    }
    bool Snowflake::operator!=(const int data) const noexcept {
        return !operator==(data);
    }


    std::uint64_t Snowflake::GetTimestamp() const noexcept {
        return (m_data >> 22) + 1420070400000;
    }
    std::uint8_t Snowflake::GetWorkerID() const noexcept {
        return static_cast<std::uint8_t>((m_data & 0x3E0000) >> 17);
    }
    std::uint8_t Snowflake::GetProcessID() const noexcept {
        return static_cast<std::uint8_t>((m_data & 0x1F000) >> 12);
    }
    std::uint16_t Snowflake::IncrementNumber() const noexcept {
        return m_data & 0xFFF;
    }

    std::uint64_t Snowflake::GetData() const noexcept {
        return m_data;
    }
    Snowflake::operator std::uint64_t() const noexcept {
        return GetData();
    }

    std::string Snowflake::ToString() const noexcept {
        return Utils::FormatString("%llu", m_data);
    }

    Snowflake::operator std::string() const noexcept {
        return ToString();
    }
}