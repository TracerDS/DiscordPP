#include <discord/requests/user.hpp>
#include <discord/endpoints.hpp>
#include <misc/utils.hpp>

namespace DiscordPP::Requests::User {
	GetCurrentUser::GetCurrentUser() noexcept
        : DiscordRequest(Endpoints::User::GetCurrentUser, RequestMethod::M_GET) {}

    GetUser::GetUser(const Snowflake id) noexcept
        : DiscordRequest(
            Utils::FormatString(Endpoints::User::GetUser, id.ToString()),
            RequestMethod::M_GET
        )
    {}

    ModifyCurrentUser::ModifyCurrentUser(const char* username, const char* avatar) noexcept
        : DiscordRequest(Endpoints::User::ModifyCurrentUser, RequestMethod::M_PATCH)
    {
        
    }

    GetCurrentUserGuilds::GetCurrentUserGuilds(
        const Snowflake before,
        const Snowflake after,
        const std::uint8_t limit,
        const bool withCounts
    ) noexcept : DiscordRequest(Endpoints::User::GetCurrentUserGuilds, RequestMethod::M_GET) {
        if (before != 0) {
            m_query += "before=" + before.ToString();
        }
        if (after != 0) {
            if (m_query.size() > 1)
                m_query.push_back('&');
            m_query += "after=" + after.ToString();
        }
        if (limit != 0) {
            if (m_query.size() > 1)
                m_query.push_back('&');
            m_query += "limit=" + std::to_string(limit);
        }
        if (withCounts){
            if (m_query.size() > 1)
                m_query.push_back('&');
            m_query += "with_counts=" + withCounts ? "true" : "false";
        }
    }
    
    GetCurrentUserGuildMember::GetCurrentUserGuildMember(const Snowflake id) noexcept
        : DiscordRequest(
            Utils::FormatString(Endpoints::User::GetCurrentUserGuildMember, id.ToString()),
            RequestMethod::M_GET
        )
    {}

    LeaveGuild::LeaveGuild(const Snowflake id) noexcept
        : DiscordRequest(
            Utils::FormatString(Endpoints::User::LeaveGuild, id.ToString()),
            RequestMethod::M_DELETE
        )
    {}
    
    CreateDM::CreateDM(const Snowflake recipient) noexcept
		: DiscordRequest(Endpoints::User::CreateDM, RequestMethod::M_POST)
    {
        if(recipient) {
            m_query += "recipient_id=" + recipient.ToString();
        }
    }

    CreateGroupDM::CreateGroupDM (
        const char** accessTokens,
        std::vector<std::pair<const char*, const char*>> nicks
    ) noexcept
		: DiscordRequest(Endpoints::User::CreateGroupDM, RequestMethod::M_POST)
    {

    }

    GetCurrentUserConnections::GetCurrentUserConnections() noexcept
		: DiscordRequest(Endpoints::User::GetCurrentUserConnections, RequestMethod::M_GET)
    {}

    GetCurrentUserApplicationRoleConnection::GetCurrentUserApplicationRoleConnection() noexcept
		: DiscordRequest(Endpoints::User::GetCurrentUserApplicationRoleConnection, RequestMethod::M_GET)
    {}
	
	UpdateCurrentUserApplicationRoleConnection::UpdateCurrentUserApplicationRoleConnection(
        const std::string platformName,
        const std::string platformUsername,
        const std::string metadata
    ) noexcept
        : DiscordRequest(Endpoints::User::UpdateCurrentUserApplicationRoleConnection, RequestMethod::M_PUT)
    {
        if(!platformName.empty()) {
            m_query += "platform_name=" + platformName;
        }
        if(!platformUsername.empty()) {
            if(m_query.size() > 1)
                m_query.push_back('&');
            m_query += "platform_username=" + platformUsername;
        }
        if(!metadata.empty()) {
            if(m_query.size() > 1)
                m_query.push_back('&');
            m_query += "metadata=" + metadata;
        }
    }
}