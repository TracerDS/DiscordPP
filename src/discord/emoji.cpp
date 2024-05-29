#include <discord/emoji.hpp>

namespace DiscordPP {
    Emoji ParseEmoji(const rapidjson::Value& value) noexcept;

    Emoji::Emoji() noexcept : m_id(0), m_name(""), m_roles({}), m_user(),
        m_requireColons(false), m_managed(false), m_animated(false),
        m_available(false) {}

    Emoji::Emoji(const rapidjson::Value& value) noexcept {
        *this = ParseEmoji(value);
    }

    Emoji::Emoji(
        Snowflake id,
        std::string name,
        std::vector<Role> roles,
        User user,
        bool requireColons,
        bool managed,
        bool animated,
        bool available
    ) noexcept : m_id(id), m_name(name), m_roles(roles), m_user(user),
        m_requireColons(requireColons), m_managed(managed), m_animated(animated),
        m_available(available)
    {}

    Emoji ParseEmoji(const rapidjson::Value& value) noexcept {
        Snowflake m_id;
		std::string m_name;
		std::vector<Role> m_roles;
		User m_user;
		bool m_requireColons;
		bool m_managed;
		bool m_animated;
		bool m_available;

        if(value.HasMember("id")) {
            m_id = Utils::Json::GetString(value["id"]);
        }
        if(value.HasMember("name")) {
            m_name = Utils::Json::GetString(value["name"]);
        }
        if(value.HasMember("roles")) {
            auto rolesArr = Utils::Json::GetArraySafe(value["roles"]);
            if(rolesArr.has_value()) {
                for(const auto& role : rolesArr.value()) {
                    m_roles.push_back(Role(role));
                }
            }
        }
        if(value.HasMember("user")) {
            auto userObj = Utils::Json::GetObjectSafe(value["user"]);
            if(userObj.has_value())
                m_user = User(userObj.value());
        }
        if(value.HasMember("require_colons")) {
            m_requireColons = Utils::Json::GetBool(value["require_colons"]);
        }
        if(value.HasMember("managed")) {
            m_managed = Utils::Json::GetBool(value["managed"]);
        }
        if(value.HasMember("animated")) {
            m_animated = Utils::Json::GetBool(value["animated"]);
        }
        if(value.HasMember("available")) {
            m_available = Utils::Json::GetBool(value["available"]);
        }

        return Emoji(
            m_id, m_name, m_roles, m_user, m_requireColons, m_managed, m_animated, m_available
        );
    }
}