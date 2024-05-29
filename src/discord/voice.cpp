#include <discord/voice.hpp>

namespace DiscordPP {
    const std::unordered_map<const char*, VoiceRegion> ms_regions = {
        { "brazil", VoiceRegion("brazil", "Brazil", false, false, false) },
        { "hongkong", VoiceRegion("hongkong", "Hong Kong", false, false, false) },
        { "india", VoiceRegion("india", "India", false, false, false) },
        { "japan", VoiceRegion("japan", "Japan", false, false, false) },
        { "rotterdam", VoiceRegion("rotterdam", "Rotterdam", false, false, false) },
        { "russia", VoiceRegion("russia", "Russia", false, false, false) },
        { "singapore", VoiceRegion("singapore", "Singapore", false, false, false) },
        { "southafrica", VoiceRegion("southafrica", "South Africa", false, false, false) },
        { "sydney", VoiceRegion("sydney", "Sydney", false, false, false) },
        { "us-central", VoiceRegion("us-central", "US Central", false, false, false) },
        { "us-east", VoiceRegion("us-east", "US East", false, false, false) },
        { "us-south", VoiceRegion("us-south", "US South", false, false, false) },
        { "us-west", VoiceRegion("us-west", "US West", false, false, false) },
    };

    VoiceRegion::VoiceRegion() noexcept : m_id(""), m_name(""), m_optimal(false),
        m_deprecated(false), m_custom(false) {}

    VoiceRegion::VoiceRegion (
        std::string id,
        std::string name,
        bool optimal,
        bool deprecated,
        bool custom
    ) noexcept : m_id(id), m_name(m_name), m_optimal(m_optimal),
        m_deprecated(m_deprecated), m_custom(m_custom) {}

    
    bool VoiceRegion::operator==(const VoiceRegion rhs) const noexcept {
        if(this->m_id != rhs.m_id) return false;
        if(this->m_name != rhs.m_name) return false;
        if(this->m_optimal != rhs.m_optimal) return false;
        if(this->m_deprecated != rhs.m_deprecated) return false;
        if(this->m_custom != rhs.m_custom) return false;
        return true;
    }
    bool VoiceRegion::operator!=(const VoiceRegion rhs) const noexcept {
        return !operator==(rhs);
    }

    std::string VoiceRegion::GetID() const noexcept { return m_id; }
    std::string VoiceRegion::GetName() const noexcept { return m_name; }
    bool VoiceRegion::IsOptimal() const noexcept { return m_optimal; }
    bool VoiceRegion::IsDeprecated() const noexcept { return m_deprecated; }
    bool VoiceRegion::IsCustom() const noexcept { return m_custom; }

    VoiceRegion VoiceRegion::GetRegionByID(const char* id) noexcept {
        return ms_regions.contains(id) ? ms_regions.at(id) : VoiceRegion();
    }
}