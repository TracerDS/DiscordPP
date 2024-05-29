#pragma once

#include <string>
#include <unordered_map>

namespace DiscordPP {
    class VoiceRegion {
        // unique ID for the region
        std::string m_id;
        
        // name of the region
        std::string m_name;
        
        // true for a single server that is closest to the current user's client
        bool m_optimal;
        
        // whether this is a deprecated voice region (avoid switching to these)
        bool m_deprecated;
        
        // whether this is a custom voice region (used for events/etc)
        bool m_custom;
    public:
        VoiceRegion() noexcept;
        VoiceRegion (
            std::string id,
            std::string name,
            bool optimal,
            bool deprecated,
            bool custom
        ) noexcept;

        bool operator==(const VoiceRegion rhs) const noexcept;
        bool operator!=(const VoiceRegion rhs) const noexcept;

        std::string GetID() const noexcept;
        std::string GetName() const noexcept;
        bool IsOptimal() const noexcept;
        bool IsDeprecated() const noexcept;
        bool IsCustom() const noexcept;

        static VoiceRegion GetRegionByID(const char* id) noexcept;
    };
}