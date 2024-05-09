#pragma once

#include <string>
#include <vector>
#include <unordered_map>

#include <rapidjson/document.h>

#include <discord/snowflake.hpp>
#include <discord/user.hpp>
#include <discord/team.hpp>
#include <discord/guild.hpp>

namespace DiscordPP {
    // AKA Application
    class Bot {
    public:
        struct InstallParams {
            std::vector<std::string> scopes;
            std::string permissions;
        };
        enum class IntegrationType {
            GUILD_INSTALL = 0,
            USER_INSTALL = 1,
        };
    protected:
        // ID of the app
        Snowflake m_id;

        // Name of the app
        std::string m_name;

        // Icon hash of the app
        std::string m_icon;

        // Description of the app
        std::string m_description;

        // List of RPC origin URLs, if RPC is enabled
        std::vector<std::string> m_rpcOrigins;

        // When false, only the app owner can add the app to guilds
        bool m_isBotPublic;

        // When true, the app's bot will only join upon completion of the full OAuth2 code grant flow
        bool m_isBotRequireCodeGrant;

        // Partial user object for the bot user associated with the app
        User m_bot;

        // URL of the app's Terms of Service
        std::string m_TOSURL;

        // URL of the app's Privacy Policy
        std::string m_privacyPolicyURL;

        // Partial user object for the owner of the app
        User m_owner;

        // Hex encoded key for verification in interactions and the GameSDK's GetTicket
        std::string m_verifyKey;

        // If the app belongs to a team, this will be a list of the members of that team
        Team m_team;

        // Guild associated with the app. For example, a developer support server.
        Snowflake m_guildID;

        // Partial object of the associated guild
        Guild m_guild;

        // If this app is a game sold on Discord, this field will be the id of the "Game SKU" that is created, if exists
        Snowflake m_primarySKUID;

        // If this app is a game sold on Discord, this field will be the URL slug that links to the store page
        std::string m_slug;

        // App's default rich presence invite cover image hash
        std::string m_coverImage;

        // App's public flags
        int m_flags;

        // Approximate count of guilds the app has been added to
        int m_approximateGuildCount;

        // Array of redirect URIs for the app
        std::vector<std::string> m_redirectURIs;

        // Interactions endpoint URL for the app
        std::string m_interactionsEndpointURL;

        // Role connection verification URL for the app
        std::string m_roleConnectionsVerificationURL;

        // List of tags describing the content and functionality of the app. Max of 5 tags.
        std::vector<std::string> m_tags;

        // Settings for the app's default in-app authorization link, if enabled
        InstallParams m_installParams;

        // In preview. Default scopes and permissions for each supported installation context.
        // Value for each key is an integration type configuration object
        std::unordered_map<IntegrationType, InstallParams> m_integrationTypesConfig;

        // Default custom authorization URL for the app, if enabled
        std::string m_customInstallURL;

    public:
        Bot() noexcept {}
        Bot(const rapidjson::Value& object) noexcept;
    };
}