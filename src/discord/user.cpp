#include <discord/user.hpp>
#include <discord/requests/user.hpp>
#include <misc/utils.hpp>

#include <iostream>
#include <string>

namespace DiscordPP {
    User::User(const Snowflake id) noexcept :
        m_accentColor(0), m_bot(false), m_flags(0), m_mfaEnabled(false),
        m_id(id), m_premiumType(PremiumType::None), m_publicFlags(0),
        m_system(false), m_verified(false) {}

    User::User(const rapidjson::Value& value) noexcept {
        this->Parse(value);        
    }

    void User::Parse(const rapidjson::Value& value) noexcept {
        auto obj = Utils::Json::GetObjectSafe(value);
        if (!obj.has_value()) return;

        auto object = obj.value();
        
        if (object.HasMember("id")) {
            m_id = Utils::Json::GetString(object["id"]);
        }
        if (object.HasMember("username")) {
            m_username = Utils::Json::GetString(object["username"]);
        }
        if (object.HasMember("discriminator")) {
            m_discriminator = Utils::Json::GetString(object["discriminator"]);
        }
        if (object.HasMember("global_name")) {
            m_globalName = Utils::Json::GetString(object["global_name"]);
        }
        if (object.HasMember("avatar")) {
            m_avatar = Utils::Json::GetString(object["avatar"]);
        }
        if (object.HasMember("bot")) {
            m_bot = Utils::Json::GetBool(object["bot"]);
        }
        if (object.HasMember("system")) {
            m_system = Utils::Json::GetBool(object["system"]);
        }
        if (object.HasMember("mfa_enabled")) {
            m_mfaEnabled = Utils::Json::GetBool(object["mfa_enabled"]);
        }
        if (object.HasMember("banner")) {
            m_banner = Utils::Json::GetString(object["banner"]);
        }
        if (object.HasMember("accent_color")) {
            m_accentColor = Utils::Json::GetUint64(object["accent_color"]);
        }
        if (object.HasMember("locale")) {
            m_locale = Utils::Json::GetString(object["locale"]);
        }
        if (object.HasMember("verified")) {
            m_verified = Utils::Json::GetBool(object["verified"]);
        }
        if (object.HasMember("email")) {
            m_email = Utils::Json::GetString(object["email"]);
        }
        if (object.HasMember("flags")) {
            m_flags = Utils::Json::GetUint64(object["flags"]);
        }
        if (object.HasMember("premium_type")) {
            m_premiumType = Utils::ValueToEnum<PremiumType>(
                Utils::Json::GetUint64(object["premium_type"])
            );
        }
        if (object.HasMember("public_flags")) {
            m_publicFlags = Utils::Json::GetUint64(object["public_flags"]);
        }
        if (object.HasMember("avatar_decoration_data")) {
            auto avatarObj = Utils::Json::GetObjectSafe(object["avatar_decoration_data"]);
            if(avatarObj.has_value()) {
                auto avatar = avatarObj.value();
                if(avatar.HasMember("asset")) {
                    m_avatarDecorationData.asset = Utils::Json::GetString(avatar["asset"]);
                }
                if(avatar.HasMember("sku_id")) {
                    m_avatarDecorationData.asset = Utils::Json::GetString(avatar["sku_id"]);
                }
            }
        }
    }

    bool User::LeaveGuild(const Snowflake guildID) noexcept {
        Requests::User::LeaveGuild request(guildID);
        return false;
    }
}