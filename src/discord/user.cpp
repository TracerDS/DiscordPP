#include <discord/user.hpp>
#include <discord/requests/user.hpp>
#include <utils.hpp>

#include <iostream>
#include <string>

namespace DiscordPP {
    User::User(const Snowflake id) noexcept
        : m_id(id)
    {}

    User::User(const rapidjson::Value& jsonObject) noexcept {
        if(!jsonObject.IsObject()) return;
        auto object = jsonObject.GetObject();
        const auto endIter = object.MemberEnd(); 

        
    }

    bool User::LeaveGuild(const Snowflake guildID) noexcept {
        Requests::User::LeaveGuild request(guildID);
        return false;
    }
}