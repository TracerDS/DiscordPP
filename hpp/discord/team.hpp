#pragma once

#include <rapidjson/document.h>

namespace DiscordPP {
    class Team {
    public:
        Team() noexcept {}
        Team(const rapidjson::Value& object) noexcept {}
    };
}