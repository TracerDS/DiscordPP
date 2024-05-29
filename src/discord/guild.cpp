#include <discord/guild.hpp>
#include <misc/utils.hpp>
#include <misc/jsonwrapper.hpp>

namespace DiscordPP {
    using GuildFeature = Guild::GuildFeature;
    using WelcomeScreen = Guild::WelcomeScreen;
    using WelcomeScreenChannel = WelcomeScreen::WelcomeScreenChannel;

    Guild ParseGuild(const rapidjson::Value& value) noexcept;
    GuildFeature GetGuildFeature(const std::string_view feature) noexcept;

    Guild::Guild() noexcept {}

    Guild::Guild(const rapidjson::Value& value) noexcept {
        *this = ParseGuild(value);
    }

    Guild::Guild(
        Snowflake id,
        std::string name,
        std::string icon,
        std::string iconHash,
        std::string splash,
        std::string discoverySplash,
        bool owner,
        Snowflake ownerID,
        std::string permissions,
        VoiceRegion region,
        Snowflake afkChannelID,
        std::uint32_t afkTimeout,
        bool widgetEnabled,
        Snowflake widgetChannelID,
        Guild::VerificationLevel verificationLevel,
        Guild::MessageNotificationLevel defaultMessageNotifications,
        Guild::ExplicitContentFilterLevel explicitContentFilter,
        std::vector<Role> roles,
        std::vector<Emoji> emojis,
        std::vector<GuildFeature> features,
        Guild::MFALevel mfaLevel,
        Snowflake applicationID,
        Snowflake systemChannelID,
        std::uint8_t systemChannelFlags,
        Snowflake rulesChannelID,
        std::uint32_t maxPresences,
        std::uint32_t maxMembers,
        std::string vanityUrlCode,
        std::string description,
        std::string banner,
        Guild::PremiumTier premiumTier,
        std::uint32_t premiumSubscriptionCount,
        Locale preferredLocale,
        Snowflake publicUpdatesChannelID,
        std::uint32_t maxVideoChannelUsers,
        std::uint32_t maxStageVideoChannelUsers,
        std::uint32_t approximateMemberCount,
        std::uint32_t approximatePresenceCount,
        WelcomeScreen welcomeScreen,
        Guild::NSFWLevel nsfwLevel,
        std::vector<StickerObject> stickers,
        bool premiumProgressBarEnabled,
        Snowflake safetyAlertsChannelID
    ) noexcept : m_id(id), m_name(name), m_icon(icon), m_iconHash(iconHash), m_splash(splash),
        m_discoverySplash(discoverySplash), m_owner(owner), m_ownerID(ownerID),
        m_permissions(permissions), m_region(region), m_afkChannelID(afkChannelID),
        m_afkTimeout(afkTimeout), m_widgetEnabled(widgetEnabled),
        m_widgetChannelID(widgetChannelID), m_verificationLevel(verificationLevel),
        m_defaultMessageNotifications(defaultMessageNotifications),
        m_explicitContentFilter(explicitContentFilter), m_roles(roles), m_emojis(emojis),
        m_features(features), m_mfaLevel(mfaLevel), m_applicationID(applicationID),
        m_systemChannelID(systemChannelID), m_systemChannelFlags(systemChannelFlags),
        m_rulesChannelID(rulesChannelID), m_maxPresences(maxPresences),
        m_maxMembers(maxMembers), m_vanityUrlCode(vanityUrlCode), m_description(description),
        m_banner(banner), m_premiumTier(premiumTier),
        m_premiumSubscriptionCount(premiumSubscriptionCount), m_preferredLocale(preferredLocale),
        m_publicUpdatesChannelID(publicUpdatesChannelID), m_maxVideoChannelUsers(maxVideoChannelUsers),
        m_maxStageVideoChannelUsers(maxStageVideoChannelUsers),
        m_approximateMemberCount(approximateMemberCount),
        m_approximatePresenceCount(approximatePresenceCount), m_welcomeScreen(welcomeScreen),
        m_nsfwLevel(nsfwLevel), m_stickers(stickers),
        m_premiumProgressBarEnabled(premiumProgressBarEnabled),
        m_safetyAlertsChannelID(safetyAlertsChannelID)
    {}

    Guild& Guild::operator=(const Guild& rhs) noexcept {
        if(*this == rhs)
            return *this;

        this->m_id = rhs.m_id;
		this->m_name = rhs.m_name;
		this->m_icon = rhs.m_icon;
		this->m_iconHash = rhs.m_iconHash;
		this->m_splash = rhs.m_splash;
		this->m_discoverySplash = rhs.m_discoverySplash;
		this->m_owner = rhs.m_owner;
		this->m_ownerID = rhs.m_ownerID;
		this->m_permissions = rhs.m_permissions;
		this->m_region = rhs.m_region;
		this->m_afkChannelID = rhs.m_afkChannelID;
		this->m_afkTimeout = rhs.m_afkTimeout;
		this->m_widgetEnabled = rhs.m_widgetEnabled;
		this->m_widgetChannelID = rhs.m_widgetChannelID;
		this->m_verificationLevel = rhs.m_verificationLevel;
		this->m_defaultMessageNotifications = rhs.m_defaultMessageNotifications;
		this->m_explicitContentFilter = rhs.m_explicitContentFilter;
		this->m_roles = rhs.m_roles;
		this->m_emojis = rhs.m_emojis;
		this->m_features = rhs.m_features;
		this->m_mfaLevel = rhs.m_mfaLevel;
		this->m_applicationID = rhs.m_applicationID;
		this->m_systemChannelID = rhs.m_systemChannelID;
		this->m_systemChannelFlags = rhs.m_systemChannelFlags;
		this->m_rulesChannelID = rhs.m_rulesChannelID;
		this->m_maxPresences = rhs.m_maxPresences;
		this->m_maxMembers = rhs.m_maxMembers;
		this->m_vanityUrlCode = rhs.m_vanityUrlCode;
		this->m_description = rhs.m_description;
		this->m_banner = rhs.m_banner;
		this->m_premiumTier = rhs.m_premiumTier;
		this->m_premiumSubscriptionCount = rhs.m_premiumSubscriptionCount;
		this->m_preferredLocale = rhs.m_preferredLocale;
		this->m_publicUpdatesChannelID = rhs.m_publicUpdatesChannelID;
		this->m_maxVideoChannelUsers = rhs.m_maxVideoChannelUsers;
		this->m_maxStageVideoChannelUsers = rhs.m_maxStageVideoChannelUsers;
		this->m_approximateMemberCount = rhs.m_approximateMemberCount;
		this->m_approximatePresenceCount = rhs.m_approximatePresenceCount;
		this->m_welcomeScreen = rhs.m_welcomeScreen;
		this->m_nsfwLevel = rhs.m_nsfwLevel;
		this->m_stickers = rhs.m_stickers;
		this->m_premiumProgressBarEnabled = rhs.m_premiumProgressBarEnabled;
		this->m_safetyAlertsChannelID = rhs.m_safetyAlertsChannelID;

        return *this;
    }

    bool Guild::operator==(const Guild rhs) const noexcept {
        if(this->m_id != rhs.m_id) return false;
        if(this->m_name != rhs.m_name) return false;
        if(this->m_icon != rhs.m_icon) return false;
        if(this->m_iconHash != rhs.m_iconHash) return false;
        if(this->m_splash != rhs.m_splash) return false;
        if(this->m_discoverySplash != rhs.m_discoverySplash) return false;
        if(this->m_owner != rhs.m_owner) return false;
        if(this->m_ownerID != rhs.m_ownerID) return false;
        if(this->m_permissions != rhs.m_permissions) return false;
        if(this->m_region != rhs.m_region) return false;
        if(this->m_afkChannelID != rhs.m_afkChannelID) return false;
        if(this->m_afkTimeout != rhs.m_afkTimeout) return false;
        if(this->m_widgetEnabled != rhs.m_widgetEnabled) return false;
        if(this->m_widgetChannelID != rhs.m_widgetChannelID) return false;
        if(this->m_verificationLevel != rhs.m_verificationLevel) return false;
        if(this->m_defaultMessageNotifications != rhs.m_defaultMessageNotifications) return false;
        if(this->m_explicitContentFilter != rhs.m_explicitContentFilter) return false;
        if(this->m_roles != rhs.m_roles) return false;
        if(this->m_emojis != rhs.m_emojis) return false;
        if(this->m_features != rhs.m_features) return false;
        if(this->m_mfaLevel != rhs.m_mfaLevel) return false;
        if(this->m_applicationID != rhs.m_applicationID) return false;
        if(this->m_systemChannelID != rhs.m_systemChannelID) return false;
        if(this->m_systemChannelFlags != rhs.m_systemChannelFlags) return false;
        if(this->m_rulesChannelID != rhs.m_rulesChannelID) return false;
        if(this->m_maxPresences != rhs.m_maxPresences) return false;
        if(this->m_maxMembers != rhs.m_maxMembers) return false;
        if(this->m_vanityUrlCode != rhs.m_vanityUrlCode) return false;
        if(this->m_description != rhs.m_description) return false;
        if(this->m_banner != rhs.m_banner) return false;
        if(this->m_premiumTier != rhs.m_premiumTier) return false;
        if(this->m_premiumSubscriptionCount != rhs.m_premiumSubscriptionCount) return false;
        if(this->m_preferredLocale != rhs.m_preferredLocale) return false;
        if(this->m_publicUpdatesChannelID != rhs.m_publicUpdatesChannelID) return false;
        if(this->m_maxVideoChannelUsers != rhs.m_maxVideoChannelUsers) return false;
        if(this->m_maxStageVideoChannelUsers != rhs.m_maxStageVideoChannelUsers) return false;
        if(this->m_approximateMemberCount != rhs.m_approximateMemberCount) return false;
        if(this->m_approximatePresenceCount != rhs.m_approximatePresenceCount) return false;
        if(this->m_welcomeScreen != rhs.m_welcomeScreen) return false;
        if(this->m_nsfwLevel != rhs.m_nsfwLevel) return false;
        if(this->m_stickers != rhs.m_stickers) return false;
        if(this->m_premiumProgressBarEnabled != rhs.m_premiumProgressBarEnabled) return false;
        if(this->m_safetyAlertsChannelID != rhs.m_safetyAlertsChannelID) return false;

        return true;
    }

    bool Guild::operator!=(const Guild rhs) const noexcept {
        return !operator==(rhs);
    }
    
    bool WelcomeScreen::operator==(const WelcomeScreen& rhs) const noexcept {
        if(this->m_description != rhs.m_description) return false;
        if(this->m_welcomeChannels != rhs.m_welcomeChannels) return false;
        return true;
    }
    bool WelcomeScreen::operator!=(const WelcomeScreen& rhs) const noexcept {
        return !operator==(rhs);
    }

    std::string WelcomeScreen::GetDescription() const noexcept { return m_description; }
    std::array<WelcomeScreenChannel, 5> WelcomeScreen::GetWelcomeChannels() const noexcept {
        return m_welcomeChannels;
    }
    
    bool WelcomeScreenChannel::operator==(const WelcomeScreenChannel& rhs) const noexcept {
        if(this->m_channelID != rhs.m_channelID) return false;
        if(this->m_description != rhs.m_description) return false;
        if(this->m_emojiID != rhs.m_emojiID) return false;
        if(this->m_emojiName != rhs.m_emojiName) return false;
        return true;
    }
    bool WelcomeScreenChannel::operator!=(const WelcomeScreenChannel& rhs) const noexcept {
        return !operator==(rhs);
    }
    
    Snowflake WelcomeScreenChannel::GetChannelID() const noexcept { return m_channelID; }
    std::string WelcomeScreenChannel::GetDescription() const noexcept { return m_description; }
    Snowflake WelcomeScreenChannel::GetEmojiID() const noexcept { return m_emojiID; }
    std::string WelcomeScreenChannel::GetEmojiName() const noexcept { return m_emojiName; }
    
    Guild ParseGuild(const rapidjson::Value& value) noexcept {
		Snowflake m_id;
		std::string m_name;
		std::string m_icon;
		std::string m_iconHash;
		std::string m_splash;
		std::string m_discoverySplash;
		bool m_owner;
		Snowflake m_ownerID;
		std::string m_permissions;
		VoiceRegion m_region;
		Snowflake m_afkChannelID;
		std::uint32_t m_afkTimeout;
		bool m_widgetEnabled;
		Snowflake m_widgetChannelID;
		Guild::VerificationLevel m_verificationLevel;
		Guild::MessageNotificationLevel m_defaultMessageNotifications;
		Guild::ExplicitContentFilterLevel m_explicitContentFilter;
		std::vector<Role> m_roles;
		std::vector<Emoji> m_emojis;
		std::vector<GuildFeature> m_features;
		Guild::MFALevel m_mfaLevel;
		Snowflake m_applicationID;
		Snowflake m_systemChannelID;
		std::uint8_t m_systemChannelFlags;
		Snowflake m_rulesChannelID;
		std::uint32_t m_maxPresences;
		std::uint32_t m_maxMembers;
		std::string m_vanityUrlCode;
		std::string m_description;
		std::string m_banner;
		Guild::PremiumTier m_premiumTier;
		std::uint32_t m_premiumSubscriptionCount;
		Locale m_preferredLocale;
		Snowflake m_publicUpdatesChannelID;
		std::uint32_t m_maxVideoChannelUsers;
		std::uint32_t m_maxStageVideoChannelUsers;
		std::uint32_t m_approximateMemberCount;
		std::uint32_t m_approximatePresenceCount;
		WelcomeScreen m_welcomeScreen;
		Guild::NSFWLevel m_nsfwLevel;
		std::vector<StickerObject> m_stickers;
		bool m_premiumProgressBarEnabled;
		Snowflake m_safetyAlertsChannelID;

        if (value.HasMember("id")) {
            m_id = Utils::Json::GetString(value["id"]);
        }
        if (value.HasMember("name")) {
            m_name = Utils::Json::GetString(value["name"]);
        }
        if (value.HasMember("icon")) {
            m_icon = Utils::Json::GetString(value["icon"]);
        }
        if (value.HasMember("splash")) {
            m_splash = Utils::Json::GetString(value["splash"]);
        }
        if (value.HasMember("discovery_splash")) {
            m_discoverySplash = Utils::Json::GetString(value["discovery_splash"]);
        }
        if (value.HasMember("owner")) {
            m_owner = Utils::Json::GetBool(value["owner"]);
        }
        if (value.HasMember("owner_id")) {
            m_ownerID = Utils::Json::GetString(value["owner_id"]);
        }
        if (value.HasMember("permissions")) {
            m_permissions = Utils::Json::GetString(value["permissions"]);
        }
        if (value.HasMember("region")) {
            m_region = VoiceRegion::GetRegionByID(Utils::Json::GetString(value["region"]).c_str());
        }
        if (value.HasMember("afk_channel_id")) {
            m_afkChannelID = Utils::Json::GetString(value["afk_channel_id"]);
        }
        if (value.HasMember("afk_timeout")) {
            m_afkTimeout = Utils::Json::GetUint64(value["afk_timeout"]);
        }
        if (value.HasMember("widget_enabled")) {
            m_widgetEnabled = Utils::Json::GetBool(value["widget_enabled"]);
        }
        if (value.HasMember("widget_channel_id")) {
            m_widgetChannelID = Utils::Json::GetString(value["widget_channel_id"]);
        }
        if (value.HasMember("verification_level")) {
            switch(Utils::Json::GetUint(value["verification_level"])) {
                default:
                case 0:
                    m_verificationLevel = Guild::VerificationLevel::NONE;
                    break;
                case 1:
                    m_verificationLevel = Guild::VerificationLevel::LOW;
                    break;
                case 2:
                    m_verificationLevel = Guild::VerificationLevel::MEDIUM;
                    break;
                case 3:
                    m_verificationLevel = Guild::VerificationLevel::HIGH;
                    break;
                case 4:
                    m_verificationLevel = Guild::VerificationLevel::VERY_HIGH;
                    break;
            }
        }
        if (value.HasMember("default_message_notifications")) {
            switch(Utils::Json::GetUint(value["default_message_notifications"])) {
                default:
                case 0:
                    m_defaultMessageNotifications = Guild::MessageNotificationLevel::ALL_MESSAGES;
                    break;
                case 1:
                    m_defaultMessageNotifications = Guild::MessageNotificationLevel::ONLY_MENTIONS;
                    break;
            }
        }

        if(value.HasMember("explicit_content_filter")) {
            switch(Utils::Json::GetUint(value["explicit_content_filter"])) {
                default:
                case 0:
                    m_explicitContentFilter = Guild::ExplicitContentFilterLevel::DISABLED;
                    break;
                case 1:
                    m_explicitContentFilter = Guild::ExplicitContentFilterLevel::MEMBERS_WITHOUT_ROLES;
                    break;
                case 2:
                    m_explicitContentFilter = Guild::ExplicitContentFilterLevel::ALL_MEMBERS;
                    break;
            }
        }
		if(value.HasMember("roles")) {
            auto arrObj = Utils::Json::GetArraySafe(value["roles"]);
            if(arrObj.has_value()) {
                for(const auto& roleValue : arrObj.value()) {
                    m_roles.push_back(Role(roleValue));
                }
            }
        }
		if(value.HasMember("emojis")) {
            auto arrObj = Utils::Json::GetArraySafe(value["emojis"]);
            if(arrObj.has_value()) {
                for(const auto& emojiValue : arrObj.value()) {
                    m_emojis.push_back(Emoji(emojiValue));
                }
            }
        }
		if(value.HasMember("features")) {
            auto arrObj = Utils::Json::GetArraySafe(value["features"]);
            if(arrObj.has_value()) {
                for(const auto& featureValue : arrObj.value()) {
                    m_features.push_back(GetGuildFeature(Utils::Json::GetString(featureValue)));
                }
            }
        }
		if(value.HasMember("mfa_level")) {
            switch(Utils::Json::GetUint(value["mfa_level"])) {
                default:
                case 0:
                    m_mfaLevel = Guild::MFALevel::NONE;
                    break;
                case 1:
                    m_mfaLevel = Guild::MFALevel::ELEVATED;
                    break;
            }
        }
		if(value.HasMember("application_id")) {
            m_applicationID = Utils::Json::GetString(value["application_id"]);
        }
        if(value.HasMember("system_channel_id")) {
            m_systemChannelID = Utils::Json::GetString(value["system_channel_id"]);
        }
        if(value.HasMember("system_channel_flags")) {
            m_systemChannelFlags = Utils::Json::GetUint(value["system_channel_flags"]);
        }
		if(value.HasMember("rules_channel_id")) {
            m_rulesChannelID = Utils::Json::GetString(value["rules_channel_id"]);
        }
		if(value.HasMember("max_presences")) {
            m_maxPresences = Utils::Json::GetUint(value["max_presences"]);
        }
		if(value.HasMember("max_members")) {
            m_maxMembers = Utils::Json::GetUint(value["max_members"]);
        }
		if(value.HasMember("vanity_url_code")) {
            m_vanityUrlCode = Utils::Json::GetString(value["vanity_url_code"]);
        }
		if(value.HasMember("description")) {
            m_description = Utils::Json::GetString(value["description"]);
        }
		if(value.HasMember("banner")) {
            m_banner = Utils::Json::GetString(value["banner"]);
        }
		if(value.HasMember("premium_tier")) {
            switch(Utils::Json::GetUint(value["premium_tier"])) {
                default:
                case 0:
                    m_premiumTier = Guild::PremiumTier::NONE;
                    break;
                case 1:
                    m_premiumTier = Guild::PremiumTier::TIER_1;
                    break;
                case 2:
                    m_premiumTier = Guild::PremiumTier::TIER_2;
                    break;
                case 3:
                    m_premiumTier = Guild::PremiumTier::TIER_3;
                    break;
            }
        }
		if(value.HasMember("premium_subscription_count")) {
            m_premiumSubscriptionCount = Utils::Json::GetUint(value["premium_subscription_count"]);
        }
		if(value.HasMember("preferred_locale")) {
            m_preferredLocale = Locale::GetLocaleByID(Utils::Json::GetString(value["preferred_locale"]).c_str());
        }
		if(value.HasMember("public_updates_channel_id")) {
            m_publicUpdatesChannelID = Utils::Json::GetString(value["public_updates_channel_id"]);
        }
		if(value.HasMember("max_video_channel_users")) {
            m_maxVideoChannelUsers = Utils::Json::GetUint(value["max_video_channel_users"]);
        }
		if(value.HasMember("max_stage_video_channel_users")) {
            m_maxStageVideoChannelUsers = Utils::Json::GetUint(value["max_stage_video_channel_users"]);
        }
		if(value.HasMember("approximate_member_count")) {
            m_approximateMemberCount = Utils::Json::GetUint(value["approximate_member_count"]);
        }
		if(value.HasMember("approximate_presence_count")) {
            m_approximatePresenceCount = Utils::Json::GetUint(value["approximate_presence_count"]);
        }
		if(value.HasMember("welcome_screen")) {
            auto welcomeScreenObj = Utils::Json::GetObjectSafe(value["welcome_screen"]);
            if(welcomeScreenObj.has_value()) {
                auto welcomeScreen = welcomeScreenObj.value();
                
                std::string description;
                std::array<WelcomeScreenChannel, 5> channels;

                if(welcomeScreen.HasMember("description")) {
                    description = Utils::Json::GetString(welcomeScreen["description"]);
                }
                if(welcomeScreen.HasMember("welcome_channels")) {
                    auto channelArr = Utils::Json::GetArraySafe(welcomeScreen["welcome_channels"]);
                    if(channelArr.has_value()) {
                        auto i = 0;
                        for(auto& channel : channelArr.value()) {
                            if(i == 5) { break; }

                            Snowflake channelID;
                            std::string description;
                            Snowflake emojiID;
                            std::string emojiName;

                            if(channel.HasMember("channel_id")) {
                                channelID = Utils::Json::GetString(channel["channel_id"]);
                            }
                            if(channel.HasMember("description")) {
                                description = Utils::Json::GetString(channel["description"]);
                            }
                            if(channel.HasMember("emoji_id")) {
                                emojiID = Utils::Json::GetString(channel["description"]);
                            }
                            if(channel.HasMember("emoji_name")) {
                                emojiName = Utils::Json::GetString(channel["description"]);
                            }
                            channels[i++] = WelcomeScreenChannel (
                                channelID, description, emojiID, emojiName
                            );
                        }
                    }
                }
                m_welcomeScreen = WelcomeScreen(description, channels);
            }
        }
		if(value.HasMember("nsfw_level")) {
            switch(Utils::Json::GetUint(value["nsfw_level"])) {
                default:
                case 0:
                    m_nsfwLevel = Guild::NSFWLevel::DEFAULT;
                    break;
                case 1:
                    m_nsfwLevel = Guild::NSFWLevel::EXPLICIT;
                    break;
                case 2:
                    m_nsfwLevel = Guild::NSFWLevel::SAFE;
                    break;
                case 3:
                    m_nsfwLevel = Guild::NSFWLevel::AGE_RESTRICTED;
                    break;
            }
        }
		if(value.HasMember("stickers")) {
            
        }
		if(value.HasMember("premium_progress_bar_enabled")) {
            m_premiumProgressBarEnabled = Utils::Json::GetBool(value["premium_progress_bar_enabled"]);
        }
		if(value.HasMember("safety_alerts_channel_id")) {
            m_safetyAlertsChannelID = Utils::Json::GetString(value["safety_alerts_channel_id"]);
        }

        return Guild(
            m_id, m_name, m_icon, m_iconHash, m_splash, m_discoverySplash, m_owner,
            m_ownerID, m_permissions, m_region, m_afkChannelID, m_afkTimeout, m_widgetEnabled,
            m_widgetChannelID, m_verificationLevel, m_defaultMessageNotifications,
            m_explicitContentFilter, m_roles, m_emojis, m_features, m_mfaLevel, m_applicationID,
            m_systemChannelID, m_systemChannelFlags, m_rulesChannelID, m_maxPresences, m_maxMembers,
            m_vanityUrlCode, m_description, m_banner, m_premiumTier, m_premiumSubscriptionCount,
            m_preferredLocale, m_publicUpdatesChannelID, m_maxVideoChannelUsers,
            m_maxStageVideoChannelUsers, m_approximateMemberCount, m_approximatePresenceCount,
            m_welcomeScreen, m_nsfwLevel, m_stickers, m_premiumProgressBarEnabled,
            m_safetyAlertsChannelID
        );
    }

    GuildFeature GetGuildFeature(const std::string_view feature) noexcept {
        if(feature == "ANIMATED_BANNER") {
            return GuildFeature::ANIMATED_BANNER;
        }
        if(feature == "ANIMATED_ICON") {
            return GuildFeature::ANIMATED_ICON;
        }
        if(feature == "APPLICATION_COMMAND_PERMISSIONS_V2") {
            return GuildFeature::APPLICATION_COMMAND_PERMISSIONS_V2;
        }
        if(feature == "AUTO_MODERATION") {
            return GuildFeature::AUTO_MODERATION;
        }
        if(feature == "BANNER") {
            return GuildFeature::BANNER;
        }
        if(feature == "COMMUNITY") {
            return GuildFeature::COMMUNITY;
        }
        if(feature == "CREATOR_MONETIZABLE_PROVISIONAL") {
            return GuildFeature::CREATOR_MONETIZABLE_PROVISIONAL;
        }
        if(feature == "CREATOR_STORE_PAGE") {
            return GuildFeature::CREATOR_STORE_PAGE;
        }
        if(feature == "DEVELOPER_SUPPORT_SERVER") {
            return GuildFeature::DEVELOPER_SUPPORT_SERVER;
        }
        if(feature == "DISCOVERABLE") {
            return GuildFeature::DISCOVERABLE;
        }
        if(feature == "FEATURABLE") {
            return GuildFeature::FEATURABLE;
        }
        if(feature == "INVITES_DISABLED") {
            return GuildFeature::INVITES_DISABLED;
        }
        if(feature == "INVITE_SPLASH") {
            return GuildFeature::INVITE_SPLASH;
        }
        if(feature == "MEMBER_VERIFICATION_GATE_ENABLED") {
            return GuildFeature::MEMBER_VERIFICATION_GATE_ENABLED;
        }
        if(feature == "MORE_STICKERS") {
            return GuildFeature::MORE_STICKERS;
        }
        if(feature == "NEWS") {
            return GuildFeature::NEWS;
        }
        if(feature == "PARTNERED") {
            return GuildFeature::PARTNERED;
        }
        if(feature == "PREVIEW_ENABLED") {
            return GuildFeature::PREVIEW_ENABLED;
        }
        if(feature == "RAID_ALERTS_DISABLED") {
            return GuildFeature::RAID_ALERTS_DISABLED;
        }
        if(feature == "ROLE_ICONS") {
            return GuildFeature::ROLE_ICONS;
        }
        if(feature == "ROLE_SUBSCRIPTIONS_AVAILABLE_FOR_PURCHASE") {
            return GuildFeature::ROLE_SUBSCRIPTIONS_AVAILABLE_FOR_PURCHASE;
        }
        if(feature == "ROLE_SUBSCRIPTIONS_ENABLED") {
            return GuildFeature::ROLE_SUBSCRIPTIONS_ENABLED;
        }
        if(feature == "TICKETED_EVENTS_ENABLED") {
            return GuildFeature::TICKETED_EVENTS_ENABLED;
        }
        if(feature == "VANITY_URL") {
            return GuildFeature::VANITY_URL;
        }
        if(feature == "VERIFIED") {
            return GuildFeature::VERIFIED;
        }
        if(feature == "VIP_REGIONS") {
            return GuildFeature::VIP_REGIONS;
        }
        if(feature == "WELCOME_SCREEN_ENABLED") {
            return GuildFeature::WELCOME_SCREEN_ENABLED;
        }
    }
}