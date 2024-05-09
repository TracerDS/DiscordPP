#include <discord/client.hpp>
#include <discord/requests/application.hpp>

#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/istreamwrapper.h"
#include "rapidjson/ostreamwrapper.h"
#include <rapidjson/prettywriter.h>

using namespace rapidjson;

#include <iostream>

namespace DiscordPP {
    Client::Client() noexcept : User(0) {}

    bool Client::login(const std::string token) noexcept {
        Requests::Application::GetCurrentApplication app;
        auto res = app.Execute(&m_curl, {{ "Authorization", "Bot " + token}});
        if (res.code != CURLE_OK)
            return false;

        rapidjson::Document document;
        document.Parse(res.data.c_str());

        StringBuffer buffer;
        PrettyWriter<StringBuffer> writer(buffer);
        document.Accept(writer);

        std::cout << buffer.GetString() << std::endl;


        m_id = document["id"].GetString();
        m_avatar = document["icon"].GetString();
        m_description = document["description"].GetString();

        m_isBotPublic = document["bot_public"].GetBool();
        m_isBotRequireCodeGrant = document["bot_require_code_grant"].GetBool();

        auto o = document["bot"].GetObject();
        Bot b(o);
        /*
        //m_bot = document["bot"].GetObject();
        m_TOSURL = document["terms_of_service_url"].GetString();
        m_privacyPolicyURL = document["privacy_policy_url"].GetString();
        //m_owner = document["owner"].GetObject();
        m_verifyKey = document["verify_key"].GetString();
        //m_team = document["team"].GetObject();
        m_guildID = document["guild_id"].GetString();
        //m_guild = document["guild"].GetObject();
        m_primarySKUID = document["primary_sku_id"].GetString();
        m_slug = document["slug"].GetString();
        m_coverImage = document["cover_image"].GetString();
        m_flags = document["flags"].GetInt();
        m_approximateGuildCount = document["approximate_guild_count"].GetInt();
        //m_redirectURIS = document["redirect_uris"].GetString();
        m_interactionsEndpointURL = document["interactions_endpoint_url"].GetString();
        m_roleConnectionsVerificationURL = document["role_connections_verification_url"].GetString();
        //m_tags = document["tags"].GetString();
        //m_installParams = document["install_params"].GetString();
        //m_integrationTypesConfig = document["integration_types_config"].GetString();
        m_customInstallURL = document["custom_install_url"].GetString();
        */

        return true;
    }
}