#pragma once 

namespace DiscordPP {
    class Guild {
    public:
        Guild() noexcept {}
        Guild(const rapidjson::Value& object) noexcept {}
    };
}