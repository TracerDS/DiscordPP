#include <discord/bot.hpp>

#include <iostream>

namespace DiscordPP {
    Bot::Bot(const rapidjson::Value& object) noexcept {
        if(!object.IsObject()) return;
        auto obj = object.GetObject();
        const auto endIter = obj.MemberEnd();

        if(obj.FindMember("id") != endIter) {
            m_id = obj["id"].GetString();
        }
        if(obj.FindMember("name") != endIter) {
            m_name = obj["name"].GetString();
        }
        if(obj.FindMember("icon") != endIter) {
            m_icon = obj["icon"].GetString();
        }
        if(obj.FindMember("description") != endIter) {
            m_description = obj["description"].GetString();
        }
        if(obj.FindMember("rpc_origins") != endIter) {
            auto& copy = obj["rpc_origins"];
            if (copy.IsArray()) {
                for (auto& str : copy.GetArray()) {
                    m_rpcOrigins.push_back(str.GetString());
                }
            }
        }
        if(obj.FindMember("bot_public") != endIter) {
            m_isBotPublic = obj["bot_public"].GetBool();
        }
        if(obj.FindMember("bot_require_code_grant") != endIter) {
            m_isBotRequireCodeGrant = obj["bot_require_code_grant"].GetBool();
        }
        if(obj.FindMember("bot") != endIter) {
            m_bot = User(obj["bot"]);
        }
        if(obj.FindMember("terms_of_service_url") != endIter) {
            m_TOSURL = obj["terms_of_service_url"].GetString();
        }
        if(obj.FindMember("privacy_policy_url") != endIter) {
            m_privacyPolicyURL = obj["privacy_policy_url"].GetString();
        }
        if(obj.FindMember("owner") != endIter) {
            m_owner = User(obj["owner"]);
        }
        if(obj.FindMember("verify_key") != endIter) {
            m_verifyKey = obj["verify_key"].GetString();
        }
        if(obj.FindMember("team") != endIter) {
            m_team = Team(obj["team"]);
        }
        if(obj.FindMember("guild_id") != endIter) {
            m_guildID = obj["guild_id"].GetUint64();
        }
        if(obj.FindMember("guild") != endIter) {
            m_guild = Guild(obj["guild"]);
        }
        if(obj.FindMember("primary_sku_id") != endIter) {
            m_primarySKUID = obj["primary_sku_id"].GetString();
        }
        if (obj.FindMember("slug") != endIter) {
            m_slug = obj["slug"].GetString();
        }
        if (obj.FindMember("cover_image") != endIter) {
            m_coverImage = obj["cover_image"].GetString();
        }
        if(obj.FindMember("flags") != endIter) {
            m_flags = obj["flags"].GetInt();
        }
        if(obj.FindMember("approximate_guild_count") != endIter) {
            m_approximateGuildCount = obj["approximate_guild_count"].GetInt();
        }
        if(obj.FindMember("redirect_uris") != endIter) {
            auto& copy = obj["redirect_uris"];
            if (copy.IsArray()) {
                for (auto& str : copy.GetArray()) {
                    m_redirectURIs.push_back(str.GetString());
                }
            }
        }
        if(obj.FindMember("interactions_endpoint_url") != endIter) {
            m_interactionsEndpointURL = obj["interactions_endpoint_url"].GetString();
        }
        if (obj.FindMember("role_connections_verification_url") != endIter) {
            m_roleConnectionsVerificationURL = obj["role_connections_verification_url"].GetString();
        }
        if(obj.FindMember("tags") != endIter) {
            auto& copy = obj["tags"];
            if (copy.IsArray()) {
                for (auto& str : copy.GetArray()) {
                    m_tags.push_back(str.GetString());
                }
            }
        }
        if(obj.FindMember("install_params") != endIter) {
            auto& copy = obj["install_params"];
            if (copy.IsObject()) {
            }
        }
        if(obj.FindMember("integration_types_config") != endIter) {
            //m_integrationTypesConfig = Utils::parseValue(obj["integration_types_config"]);
        }
        if(obj.FindMember("custom_install_url") != endIter) {
            m_customInstallURL = obj["custom_install_url"].GetString();
        }
    }
}