#pragma once

#include <string>

#include <discord/snowflake.hpp>
#include <misc/jsonwrapper.hpp>


namespace DiscordPP {
    class User {
    public:
        enum class Flags {
            // Discord Employee
            STAFF = 1 << 0,

            // Partnered Server Owner
            PARTNER = 1 << 1,

            // HypeSquad Events Member
            HYPESQUAD = 1 << 2,

            // Bug Hunter Level 1
            BUG_HUNTER_LEVEL_1 = 1 << 3,

            // House Bravery Member
            HYPESQUAD_ONLINE_HOUSE_1 = 1 << 6,

            // House Brilliance Member
            HYPESQUAD_ONLINE_HOUSE_2 = 1 << 7,

            // House Balance Member
            HYPESQUAD_ONLINE_HOUSE_3 = 1 << 8,

            // Early Nitro Supporter
            PREMIUM_EARLY_SUPPORTER = 1 << 9,

            // User is a team
            TEAM_PSEUDO_USER = 1 << 10,

            // Bug Hunter Level 2
            BUG_HUNTER_LEVEL_2 = 1 << 14,

            // Verified Bot
            VERIFIED_BOT = 1 << 16,

            // Early Verified Bot Developer
            VERIFIED_DEVELOPER = 1 << 17,

            // Moderator Programs Alumni
            CERTIFIED_MODERATOR = 1 << 18,

            // Bot uses only HTTP interactions and is shown in the online member list
            BOT_HTTP_INTERACTIONS = 1 << 19,

            // User is an Active Developer
            ACTIVE_DEVELOPER = 1 << 22,
        };
        enum class PremiumType {
            None = 0,
            NitroClassic = 1,
            Nitro = 2,
            NitroBasic = 3
        };
        enum class VisibilityType {
            // invisible to everyone except the user themselves
            None = 0,

            // visible to everyone
            Everyone = 1,
        };
    protected:
        // the user's id
        Snowflake m_id{};
        
        // the user's username, not unique across the platform
        std::string username{};

        // the user's Discord-tag
        std::string m_discriminator{};

        // the user's display name, if it is set. For bots, this is the application name
        std::string m_globalName{};

        // the user's avatar hash
        std::string m_avatar{};

        // whether the user belongs to an OAuth2 application
        bool m_bot{};

        // whether the user is an Official Discord System user (part of the urgent message system)
        bool m_system{};

        // whether the user has two factor enabled on their account
        bool m_mfaEnabled{};

        // the user's banner hash
        std::string m_banner{};
        
        // the user's banner color encoded as an integer representation of hexadecimal color code
        int m_accentColor{};
        
        // the user's chosen language option
        std::string m_locale{};
        
        // whether the email on this account has been verified	email
        bool m_verified{};

        // the user's email	email
        std::string m_email{};

        // the flags on a user's account
        int m_flags{};

        // the type of Nitro subscription on a user's account
        int m_premiumType{};

        // the public flags on a user's account
        int m_publicFlags{};

        // the user's avatar decoration hash
        std::string m_avatarDecoration{};
    public:
        User(const Snowflake id = 0) noexcept;
        User(const rapidjson::Value& object) noexcept;
        
        bool LeaveGuild(const Snowflake guildID) noexcept;
    };
}