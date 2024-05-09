#pragma once

#include <cstdio>
#include <vector>

#include <discord/requests/request.hpp>
#include <discord/snowflake.hpp>

namespace DiscordPP::Requests::User {
	class GetCurrentUser : public DiscordRequest {
	public:
		GetCurrentUser() noexcept;
	};

	class GetUser : public DiscordRequest {
	public:
		GetUser(const Snowflake id) noexcept;
	};

	class ModifyCurrentUser : public DiscordRequest {
	public:
		ModifyCurrentUser(const char* username, const char* avatar = 0) noexcept;
	};

	class GetCurrentUserGuilds : public DiscordRequest {
	public:
		GetCurrentUserGuilds(
			const Snowflake before = 0,
			const Snowflake after = 0,
			const std::uint8_t limit = 200,
			const bool withCounts = false
		) noexcept;
	};
	class GetCurrentUserGuildMember : public DiscordRequest {
	public:
		GetCurrentUserGuildMember(const Snowflake id) noexcept;
	};

	class LeaveGuild : public DiscordRequest {
	public:
		LeaveGuild(const Snowflake id) noexcept;
	};

	class CreateDM : public DiscordRequest {
	public:
		CreateDM(const Snowflake recipient) noexcept;
	};

	class CreateGroupDM : public DiscordRequest {
	public:
		[[deprecated(
			"Currently the endpoint is hard to use."
			"For now you cannot create group DMS with a bot"
		)]]
		CreateGroupDM(
			const char** accessTokens = 0,
			std::vector<std::pair<const char*, const char*>> nicks = {}
		) noexcept;
	};

	class GetCurrentUserConnections : public DiscordRequest {
	public:
		GetCurrentUserConnections() noexcept;
	};

	class GetCurrentUserApplicationRoleConnection : public DiscordRequest {
	public:
		GetCurrentUserApplicationRoleConnection() noexcept;
	};
	
	class UpdateCurrentUserApplicationRoleConnection : public DiscordRequest {
	public:
		UpdateCurrentUserApplicationRoleConnection(
			const std::string platformName = "",
			const std::string platformUsername = "",
			const std::string metadata = ""
		) noexcept;
	};

}