#pragma once 

#include <string_view>
#include <unordered_map>
#include <optional>

namespace DiscordPP {
    class Locale {
        const char* m_locale;
        const char* m_languageName;
        std::string_view m_nativeName;
    public:
        Locale() noexcept;
        Locale (
            const char* locale,
            const char* languageName,
            std::string_view nativeName
        ) noexcept;

        bool operator==(const Locale rhs) const noexcept;
        bool operator!=(const Locale rhs) const noexcept;

        const char* GetLocale() const noexcept;
        const char* GetLanguageName() const noexcept;
        std::string_view GetNativeName() const noexcept;

        static Locale GetLocaleByID(const char* id) noexcept;
    };
    
}