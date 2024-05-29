#include <locales.hpp>

namespace DiscordPP {
    const std::unordered_map<const char*, Locale> ms_locales = {
        { "id", Locale("id", "Indonesian", "Bahasa Indonesia") },
        { "da", Locale("da", "Danish", "Dansk") },
        { "de", Locale("de", "German", "Deutsch") },
        { "en-GB", Locale("en-GB", "English, UK", "English, UK") },
        { "en-US", Locale("en-US", "English, US", "English, US") },
        { "es-ES", Locale("es-ES", "Spanish", "Español") },
        { "es-419", Locale("es-419", "Spanish, LATAM", "Español, LATAM") },
        { "fr", Locale("fr", "French", "Français") },
        { "hr", Locale("hr", "Croatian", "Hrvatski") },
        { "it", Locale("it", "Italian", "Italiano") },
        { "lt", Locale("lt", "Lithuanian", "Lietuviškai") },
        { "hu", Locale("hu", "Hungarian", "Magyar") },
        { "nl", Locale("nl", "Dutch", "Nederlands") },
        { "no", Locale("no", "Norwegian", "Norsk") },
        { "pl", Locale("pl", "Polish", "Polski") },
        { "pt-BR", Locale("pt-BR", "Portuguese, Brazilian", "Português do Brasil") },
        { "ro", Locale("ro", "Romanian, Romania", "Română") },
        { "fi", Locale("fi", "Finnish", "Suomi") },
        { "sv-SE", Locale("sv-SE", "Swedish", "Svenska") },
        { "vi", Locale("vi", "Vietnamese", "Tiếng Việt") },
        { "tr", Locale("tr", "Turkish", "Türkçe") },
        { "cs", Locale("cs", "Czech", "Čeština") },
        { "el", Locale("el", "Greek", "Ελληνικά") },
        { "bg", Locale("bg", "Bulgarian", "български") },
        { "ru", Locale("ru", "Russian", "Pусский") },
        { "uk", Locale("uk", "Ukrainian", "Українська") },
        { "hi", Locale("hi", "Hindi", "हिन्दी") },
        { "th", Locale("th", "Thai", "ไทย") },
        { "zh-CN", Locale("zh-CN", "Chinese, China", "中文") },
        { "ja", Locale("ja", "Japanese", "日本語") },
        { "zh-TW", Locale("zh-TW", "Chinese, Taiwan", "繁體中文") },
        { "ko", Locale("ko", "Korean", "한국어") },
    };
    
    Locale::Locale () noexcept : m_locale(""), m_languageName(""), m_nativeName("") {}
    Locale::Locale (
        const char* locale,
        const char* languageName,
        std::string_view nativeName
    ) noexcept : m_locale(locale), m_languageName(languageName), m_nativeName(nativeName) {}

    bool Locale::operator==(const Locale rhs) const noexcept {
        if (this->m_locale != rhs.m_locale) return false;
        if (this->m_languageName != rhs.m_languageName) return false;
        if (this->m_nativeName != rhs.m_nativeName) return false;
        return true;
    }
    bool Locale::operator!=(const Locale rhs) const noexcept {
        return !operator==(rhs);
    }

    const char* Locale::GetLocale() const noexcept { return m_locale; }
    const char* Locale::GetLanguageName() const noexcept { return m_languageName; }
    std::string_view Locale::GetNativeName() const noexcept { return m_nativeName; }

    Locale Locale::GetLocaleByID(const char* id) noexcept {
        return ms_locales.contains(id) ? ms_locales.at(id) : Locale();
    }
}