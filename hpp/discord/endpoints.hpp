#pragma once

#include <string>

namespace DiscordPP::Endpoints {
    const auto CURRENT_VERSION = 10;
    const auto DISCORD_ENDPOINT = "https://discord.com/api/v" + std::to_string(CURRENT_VERSION);

    namespace Application {
        constexpr auto GetCurrentApplication = "/applications/@me";
        constexpr auto EditCurrentApplication = "/applications/@me";
    }
    namespace User {
        constexpr auto GetCurrentUser = "/users/@me";
        constexpr auto GetUser = "/users/%s";
        constexpr auto ModifyCurrentUser = "/users/@me";
        constexpr auto GetCurrentUserGuilds = "/users/@me/guilds";
        constexpr auto GetCurrentUserGuildMember = "/users/@me/guilds/%s/member";
        constexpr auto LeaveGuild = "/users/@me/guilds/%s";
        constexpr auto CreateDM = "/users/@me/channels";
        constexpr auto CreateGroupDM = "/users/@me/channels";
        constexpr auto GetCurrentUserConnections = "/users/@me/connections";
        constexpr auto GetCurrentUserApplicationRoleConnection = "/users/@me/applications/%s/role-connection";
        constexpr auto UpdateCurrentUserApplicationRoleConnection = "/users/@me/applications/%s/role-connection";
    }
}