#pragma once

#include <vector>

#include <discord/user.hpp>
#include <discord/role.hpp>

#include "rapidjson/document.h"

namespace DiscordPP {
    class Emoji {
    protected:
		// emoji id
		Snowflake m_id;

		// emoji name
		std::string m_name;

		// roles allowed to use this emoji
		std::vector<Role> m_roles;

		// user that created this emoji
		User m_user;

		// whether this emoji must be wrapped in colons
		bool m_requireColons;

		// whether this emoji is managed
		bool m_managed;

		// whether this emoji is animated
		bool m_animated;

		// whether this emoji can be used, may be false due to loss of Server Boosts
		bool m_available;
    public:
        Emoji() noexcept;
        Emoji(const rapidjson::Value& value) noexcept;
		Emoji(
			Snowflake id,
			std::string name,
			std::vector<Role> roles,
			User user,
			bool requireColons,
			bool managed,
			bool animated,
			bool available
		) noexcept;
    };
}