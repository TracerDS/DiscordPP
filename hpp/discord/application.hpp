#pragma once

#include <unordered_map>
#include <misc/curlwrapper.hpp>

#include <discord/user.hpp>
#include <discord/team.hpp>
#include <discord/guild.hpp>

namespace DiscordPP {
    class Application : public User {
    public:
        struct InstallParams {
            std::vector<std::string> scopes;
            std::string permissions;
        };
        
        enum class IntegrationType {
            GUILD_INSTALL,
            USER_INSTALL
        };
    protected:
        Curl m_curl;

        // Description of the app
        std::string m_description;

        // When false, only the app owner can add the app to guilds
        bool m_isBotPublic;

        // When true, the app's bot will only join upon
        // completion of the full OAuth2 code grant flow
        bool m_isBotRequireCodeGrant;

        // Partial user object for the bot user associated with the app
        User m_bot;

        // URL of the app's Terms of Service
        std::string m_TOSURL;

        // URL of the app's Privacy Policy
        std::string m_privacyPolicyURL;

        // Partial user object for the owner of the app
        User m_owner;

        // Hex encoded key for verification in
        // interactions and the GameSDK's GetTicket
        std::string m_verifyKey;

        // If the app belongs to a team, this will be
        // a list of the members of that team
        Team m_team;

        // Guild associated with the app. For example,
        // a developer support server.
        Snowflake m_guildID;

        // Partial object of the associated guild
        Guild m_guild;

        // If this app is a game sold on Discord,
        // this field will be the id of the "Game SKU"
        // that is created, if exists
        Snowflake m_primarySKUID;

        // If this app is a game sold on Discord,
        // this field will be the URL slug that links
        // to the store page
        std::string m_slug;

        // App's default rich presence invite cover image hash
        std::string m_coverImage;

        // App's public flags
        int m_flags;

        // Approximate count of guilds the app has been added to
        int m_approximateGuildCount;

        // Array of redirect URIs for the app
        std::vector<std::string> m_redirectURIS;

        // Interactions endpoint URL for the app
        std::string m_interactionsEndpointURL;

        // Role connection verification URL for the app
        std::string m_roleConnectionsVerificationURL;

        // List of tags describing the content and
        // functionality of the app. Max of 5 tags.
        std::vector<std::string> m_tags;

        // Settings for the app's default in-app authorization link, if enabled
        InstallParams m_installParams;

        // In preview.
        // Default scopes and permissions for each
        // supported installation context.
        // Value for each key is an integration type configuration object
        std::unordered_map<IntegrationType, InstallParams> m_integrationTypesConfig;

        // Default custom authorization URL for the app, if enabled
        std::string m_customInstallURL;
    public:
        Application() noexcept;
        bool login(const std::string token) noexcept;

        std::string GetDescription() const noexcept;
        bool IsBotPublic() const noexcept;
        bool IsBotRequireCodeGrant() const noexcept;
        User GetBot() const noexcept;
        std::string GetTOSURL() const noexcept;
        std::string GetPrivacyPolicyURL() const noexcept;
        User GetOwner() const noexcept;
        std::string GetVerifyKey() const noexcept;
        Team GetTeam() const noexcept;
        Snowflake GetGuildID() const noexcept;
        Guild GetGuild() const noexcept;
        Snowflake GetPrimarySKUID() const noexcept;
        std::string GetSlug() const noexcept;
        std::string GetCoverImage() const noexcept;
        int GetFlags() const noexcept;
        int GetApproximateGuildCount() const noexcept;
        std::vector<std::string> GetRedirectURIs() const noexcept;
        std::string GetInteractionsEndpointURL() const noexcept;
        std::string GetRoleConnectionsVerificationURL() const noexcept;
        std::vector<std::string> GetTags() const noexcept;

    };
}

