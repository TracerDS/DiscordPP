#include <discord/application.hpp>
#include <discord/requests/application.hpp>
#include <misc/utils.hpp>

#include "rapidjson/document.h"

using namespace rapidjson;

#include <iostream>

namespace DiscordPP {
    Application::Application() noexcept :
        User(0), m_approximateGuildCount(-1), m_flags(0),
        m_isBotPublic(false), m_isBotRequireCodeGrant(false),
        m_installParams{{}, ""} {}

    bool Application::login(const std::string token) noexcept {
        Requests::Application::GetCurrentApplication app;
        auto res = app.Execute(&m_curl, {{ "Authorization", "Bot " + token }});
        if (res.code != CURLE_OK)
            return false;

        rapidjson::Document root;
        root.Parse(res.data.c_str());

        this->Parse(root);

        return true;
    }

    void Application::Parse(const rapidjson::Value& root) noexcept {
        if (root.HasMember("id")) {
            m_id = Utils::Json::GetString(root["id"]);
        }
        if (root.HasMember("icon")) {
            m_avatar = Utils::Json::GetString(root["icon"]);
        }
        if (root.HasMember("description")) {
            m_description = Utils::Json::GetString(root["description"]);
        }
        if (root.HasMember("bot_public")) {
            m_isBotPublic = Utils::Json::GetBool(root["bot_public"]);
        }
        if (root.HasMember("bot_require_code_grant")) {
            m_isBotRequireCodeGrant = Utils::Json::GetBool(root["bot_require_code_grant"]);
        }
        if (root.HasMember("bot")) {
            auto obj = Utils::Json::GetObjectSafe(root["bot"]);
            if (obj.has_value())
                m_bot = User(obj.value());
        }
        if (root.HasMember("terms_of_service_url")) {
            m_TOSURL = Utils::Json::GetString(root["terms_of_service_url"]);
        }
        if (root.HasMember("privacy_policy_url")) {
            m_privacyPolicyURL = Utils::Json::GetString(root["privacy_policy_url"]);
        }
        if (root.HasMember("owner")) {
            auto obj = Utils::Json::GetObjectSafe(root["owner"]);
            if (obj.has_value())
                m_owner = User(obj.value());
        }
        if (root.HasMember("verify_key")) {
            m_verifyKey = Utils::Json::GetString(root["verify_key"]);
        }
        if (root.HasMember("team")) {
            auto obj = Utils::Json::GetObjectSafe(root["team"]);
            if (obj.has_value())
                m_team = Team(obj.value());
        }
        if (root.HasMember("guild_id")) {
            m_guildID = Utils::Json::GetString(root["guild_id"]);
        }
        if (root.HasMember("guild")) {
            auto obj = Utils::Json::GetObjectSafe(root["guild"]);
            if (obj.has_value())
                m_guild = Guild(obj.value());
        }
        if (root.HasMember("primary_sku_id")) {
            m_primarySKUID = Utils::Json::GetString(root["primary_sku_id"]);
        }
        if (root.HasMember("slug")) {
            m_slug = Utils::Json::GetString(root["slug"]);
        }
        if (root.HasMember("cover_image")) {
            m_coverImage = Utils::Json::GetString(root["cover_image"]);
        }
        if (root.HasMember("flags")) {
            m_flags = Utils::Json::GetInt(root["flags"]);
        }
        if (root.HasMember("approximate_guild_count")) {
            m_approximateGuildCount = Utils::Json::GetInt(
                root["approximate_guild_count"]
            );
        }
        if (root.HasMember("redirect_uris")) {
            const auto& redirectArr = Utils::Json::GetArraySafe(root["redirect_uris"]);
            if (redirectArr.has_value()) {
                for (const auto& uri : redirectArr.value()) {
                    m_redirectURIS.push_back(Utils::Json::GetString(uri));
                }
            }
        }
        if (root.HasMember("interactions_endpoint_url")) {
            m_interactionsEndpointURL = Utils::Json::GetString(
                root["interactions_endpoint_url"]
            );
        }
        if (root.HasMember("role_connections_verification_url")) {
            m_roleConnectionsVerificationURL = Utils::Json::GetString(
                root["role_connections_verification_url"]
            );
        }
        if (root.HasMember("tags")) {
            auto tags = Utils::Json::GetArraySafe(root["tags"]);
            if (tags.has_value()) {
                for (const auto& tag : root["tags"].GetArray()) {
                    m_tags.push_back(Utils::Json::GetString(tag));
                }
            }
        }
        const auto& ParseInstallParams = [&](const rapidjson::Value& v) -> InstallParams {
            InstallParams params;
            if (v.HasMember("scopes")) {
                auto scopesArr = Utils::Json::GetArraySafe(v["scopes"]);
                if (scopesArr.has_value()) {
                    for (const auto& scope : scopesArr.value()) {
                        params.scopes.push_back(Utils::Json::GetString(scope));
                    }
                }
            }
            if (v.HasMember("permissions")) {
                params.permissions = Utils::Json::GetString(v["permissions"]);
            }
            return params;
        };

        if (root.HasMember("install_params")) {
            auto obj = Utils::Json::GetObjectSafe(root["install_params"]);
            if (obj.has_value()) {
                m_installParams = ParseInstallParams(obj.value());
            }
        }
        if (root.HasMember("integration_types_config")) {
            auto integrationsObj = Utils::Json::GetObjectSafe(
                root["integration_types_config"]
            );
            if (integrationsObj.has_value()) {
                auto integrations = integrationsObj.value();

                const auto& ParseIntegrations = [&](const rapidjson::Value& v) -> InstallParams {
                    if(v.HasMember("oauth2_install_params")) {
                        return ParseInstallParams(v["oauth2_install_params"]);
                    }
                    return InstallParams();
                };

                if (integrations.HasMember("0")) {
                    m_integrationTypesConfig[IntegrationType::GUILD_INSTALL] =
                        ParseIntegrations(integrations["0"]);
                }
                if (integrations.HasMember("1")) {
                    m_integrationTypesConfig[IntegrationType::USER_INSTALL] =
                        ParseIntegrations(integrations["0"]);
                }
            }
        }
        if (root.HasMember("custom_install_url")) {
            m_customInstallURL = Utils::Json::GetString(root["custom_install_url"]);
        }
    }

}