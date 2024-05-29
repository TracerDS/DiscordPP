#pragma once

#include "rapidjson/document.h"

#include <discord/snowflake.hpp>

namespace DiscordPP {
    class Role {
    public:
        class RoleTag {
        public:
            enum class RoleTagFlags {
                // whether this is the guild's Booster role
                Premium_subscriber,
                
                // whether this role is available for purchase
                available_for_purchase,
                
                // whether this role is a guild's linked role
                guild_connections,
            };
        protected:            
            // the id of the bot this role belongs to
            Snowflake m_botID;
            
            // the id of the integration this role belongs to
            Snowflake m_integrationID;
            
            // the id of this role's subscription sku and listing
            Snowflake m_subscriptionListingID;
        public:
        };

        enum RoleFlag {
            // role can be selected by members in an onboarding prompt
            IN_PROMPT = 1 << 0,
        };
    protected:
		// role id
		Snowflake m_id;

		// role name
		std::string m_name;

		// integer representation of hexadecimal color code
		std::uint32_t m_color;

		// if this role is pinned in the user listing
		bool m_hoist;

		// role icon hash
		std::string m_icon;

		// role unicode emoji
		std::string m_unicode_emoji;

		// position of this role
		std::uint32_t m_position;

		// permission bit set
		std::string m_permissions;

		// whether this role is managed by an integration
		bool m_managed;

		// whether this role is mentionable
		bool m_mentionable;

		// the tags this role has
		RoleTag m_tags;

		// role flags combined as a bitfield
		std::uint32_t m_flags;

    public:
        Role() noexcept;
        Role(const rapidjson::Value& value) noexcept;
        Role() noexcept;
    };
}