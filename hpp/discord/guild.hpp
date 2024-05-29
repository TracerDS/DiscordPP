#pragma once 

#include <vector>
#include <array>

#include <rapidjson/document.h>

#include <discord/snowflake.hpp>
#include <discord/voice.hpp>
#include <discord/role.hpp>
#include <discord/emoji.hpp>
#include <discord/locales.hpp>

struct GuildFeatureStrings {};
struct StickerObject {};

namespace DiscordPP {
    class Guild {
	public:
		class WelcomeScreen {
		public:
			class WelcomeScreenChannel {
			protected:
				// the channel's id
				Snowflake m_channelID;
				
				// the description shown for the channel
				std::string m_description;
				
				// the emoji id, if the emoji is custom
				Snowflake m_emojiID;
				
				// the emoji name if custom, the unicode character if standard, or null if no emoji is set
				std::string m_emojiName;
			public:
				WelcomeScreenChannel() noexcept;
				WelcomeScreenChannel(
					Snowflake channelID,
					std::string description,
					Snowflake emojiID,
					std::string emojiName
				) noexcept;

				bool operator==(const WelcomeScreenChannel& rhs) const noexcept;
				bool operator!=(const WelcomeScreenChannel& rhs) const noexcept;

				Snowflake GetChannelID() const noexcept;
				std::string GetDescription() const noexcept;
				Snowflake GetEmojiID() const noexcept;
				std::string GetEmojiName() const noexcept;
			};
		protected:
			// the server description shown in the welcome screen
			std::string m_description;

			// the channels shown in the welcome screen, up to 5
			std::array<WelcomeScreenChannel, 5> m_welcomeChannels;
		public:
			WelcomeScreen() noexcept;
			WelcomeScreen(
				std::string description,
				std::array<WelcomeScreenChannel, 5> welcomeChannels
			) noexcept;

			bool operator==(const WelcomeScreen& rhs) const noexcept;
			bool operator!=(const WelcomeScreen& rhs) const noexcept;

			std::string GetDescription() const noexcept;
			std::array<WelcomeScreenChannel, 5> GetWelcomeChannels() const noexcept;
		};
		// Guild verification level
		enum class VerificationLevel {
			// unrestricted
			NONE = 0,

			// must have verified email on account
			LOW = 1,

			// must be registered on Discord for longer than 5 minutes
			MEDIUM = 2,

			// must be a member of the server for longer than 10 minutes
			HIGH = 3,

			// must have a verified phone number
			VERY_HIGH = 4,
		};

		// Guild NSFW level
		enum class NSFWLevel {
			DEFAULT = 0,
			EXPLICIT = 1,
			SAFE = 2,
			AGE_RESTRICTED = 3,
		};

		// Guild premium tier
		enum class PremiumTier {
			// guild has not unlocked any Server Boost perks
			NONE = 0,
			
			// guild has unlocked Server Boost level 1 perks
			TIER_1 = 1,
			
			// guild has unlocked Server Boost level 2 perks
			TIER_2 = 2,
			
			// guild has unlocked Server Boost level 3 perks
			TIER_3 = 3,
		};

		// Guild system channel flags
		enum class SystemChannelFlag {
			// Suppress member join notifications
			SUPPRESS_JOIN_NOTIFICATIONS = 1 << 0,
			
			// Suppress server boost notifications
			SUPPRESS_PREMIUM_SUBSCRIPTIONS = 1 << 1,
			
			// Suppress server setup tips
			SUPPRESS_GUILD_REMINDER_NOTIFICATIONS = 1 << 2,
			
			// Hide member join sticker reply buttons
			SUPPRESS_JOIN_NOTIFICATION_REPLIES = 1 << 3,
			
			// Suppress role subscription purchase and renewal notifications
			SUPPRESS_ROLE_SUBSCRIPTION_PURCHASE_NOTIFICATIONS = 1 << 4,
			
			// Hide role subscription sticker reply buttons
			SUPPRESS_ROLE_SUBSCRIPTION_PURCHASE_NOTIFICATION_REPLIES = 1 << 5,
		};

		// Guild features
		enum class GuildFeature {
			// guild has access to set an animated guild banner image
			ANIMATED_BANNER,
			
			// guild has access to set an animated guild icon
			ANIMATED_ICON,
			
			// guild is using the old permissions configuration behavior
			APPLICATION_COMMAND_PERMISSIONS_V2,
			
			// guild has set up auto moderation rules
			AUTO_MODERATION,
			
			// guild has access to set a guild banner image
			BANNER,
			
			// guild can enable welcome screen, Membership Screening,
			// stage channels and discovery, and receives community updates
			COMMUNITY,
			
			// guild has enabled monetization
			CREATOR_MONETIZABLE_PROVISIONAL,
			
			// guild has enabled the role subscription promo page
			CREATOR_STORE_PAGE,
			
			// guild has been set as a support server on the App Directory
			DEVELOPER_SUPPORT_SERVER,
			
			// guild is able to be discovered in the directory
			DISCOVERABLE,
			
			// guild is able to be featured in the directory
			FEATURABLE,
			
			// guild has paused invites, preventing new users from joining
			INVITES_DISABLED,
			
			// guild has access to set an invite splash background
			INVITE_SPLASH,
			
			// guild has enabled Membership Screening
			MEMBER_VERIFICATION_GATE_ENABLED,
			
			// guild has increased custom sticker slots
			MORE_STICKERS,
			
			// guild has access to create announcement channels
			NEWS,
			
			// guild is partnered
			PARTNERED,
			
			// guild can be previewed before joining via Membership Screening or the directory
			PREVIEW_ENABLED,
			
			// guild has disabled alerts for join raids in the configured safety alerts channel
			RAID_ALERTS_DISABLED,
			
			// guild is able to set role icons
			ROLE_ICONS,
			
			// guild has role subscriptions that can be purchased
			ROLE_SUBSCRIPTIONS_AVAILABLE_FOR_PURCHASE,
			
			// guild has enabled role subscriptions
			ROLE_SUBSCRIPTIONS_ENABLED,
			
			// guild has enabled ticketed events
			TICKETED_EVENTS_ENABLED,
			
			// guild has access to set a vanity URL
			VANITY_URL,
			
			// guild is verified
			VERIFIED,
			
			// guild has access to set 384kbps bitrate in voice (previously VIP voice servers)
			VIP_REGIONS,
			
			// guild has enabled the welcome screen
			WELCOME_SCREEN_ENABLED,
		};

		enum class MutableGuldFeature {
			// Enables Community Features in the guild
			COMMUNITY,// = Administrator,
			// Enables discovery in the guild, making it publicly listed
			DISCOVERABLE,// = Administrator*,
			// Pauses all invites/access to the server
			INVITES_DISABLED,// = Manage Guild,
			// Disables alerts for join raids
			RAID_ALERTS_DISABLED,// = Manage Guild,
		};
		enum class MessageNotificationLevel {
			// members will receive notifications for all messages by default
			ALL_MESSAGES = 0,
			
			// members will receive notifications only for messages that @mention them by default
			ONLY_MENTIONS = 1,
		};
		enum class ExplicitContentFilterLevel {
			// media content will not be scanned
			DISABLED = 0,

			// media content sent by members without roles will be scanned
			MEMBERS_WITHOUT_ROLES = 1,

			// media content sent by all members will be scanned
			ALL_MEMBERS = 2,
		};
		enum class MFALevel {
			// guild has no MFA/2FA requirement for moderation actions
			NONE = 0,
			
			// guild has a 2FA requirement for moderation actions
			ELEVATED = 1,
		};
	protected:
		// guild id
		Snowflake m_id;

		// guild name (2-100 characters, excluding trailing and leading whitespace)
		std::string m_name;

		// icon hash
		std::string m_icon;

		// icon hash, returned when in the template object
		std::string m_iconHash;

		// splash hash
		std::string m_splash;

		// discovery splash m_hash; only present for guilds with the "DISCOVERABLE" feature
		std::string m_discoverySplash;

		// true if the user is the owner of the guild
		bool m_owner;

		// id of owner
		Snowflake m_ownerID;

		// total permissions for the user in the guild (excludes overwrites and implicit permissions)
		std::string m_permissions;

		// voice region id for the guild (deprecated)
		VoiceRegion m_region;

		// id of afk channel
		Snowflake m_afkChannelID;

		// afk timeout in seconds
		std::uint32_t m_afkTimeout;

		// true if the server widget is enabled
		bool m_widgetEnabled;

		// the channel id that the widget will generate an invite to, or null if set to no invite
		Snowflake m_widgetChannelID;

		// verification level required for the guild
		VerificationLevel m_verificationLevel;

		// default message notifications level
		MessageNotificationLevel m_defaultMessageNotifications;

		// explicit content filter level
		ExplicitContentFilterLevel m_explicitContentFilter;

		// roles in the guild
		std::vector<Role> m_roles;

		// custom guild emojis
		std::vector<Emoji> m_emojis;

		// enabled guild features
		std::vector<GuildFeature> m_features;

		// required MFA level for the guild
		MFALevel m_mfaLevel;

		// application id of the guild creator if it is bot-created
		Snowflake m_applicationID;

		// the id of the channel where guild notices such as welcome messages and boost events are posted
		Snowflake m_systemChannelID;

		// system channel flags
		std::uint8_t m_systemChannelFlags;

		// the id of the channel where Community guilds can display rules and/or guidelines
		Snowflake m_rulesChannelID;

		// the maximum number of presences for the guild
		// (null is always returned, apart from the largest of guilds)
		std::uint32_t m_maxPresences;

		// the maximum number of members for the guild
		std::uint32_t m_maxMembers;

		// the vanity url code for the guild
		std::string m_vanityUrlCode;

		// the description of a guild
		std::string m_description;

		// banner hash
		std::string m_banner;

		// premium tier (Server Boost level)
		PremiumTier m_premiumTier;

		// the number of boosts this guild currently has
		std::uint32_t m_premiumSubscriptionCount;

		// the preferred locale of a Community guild;
		// used in server discovery and notices from Discord, and sent in m_interactions;
		// defaults to "en-US"
		Locale m_preferredLocale;

		// the id of the channel where admins and moderators of Community guilds receive notices from Discord
		Snowflake m_publicUpdatesChannelID;

		// the maximum amount of users in a video channel
		std::uint32_t m_maxVideoChannelUsers;

		// the maximum amount of users in a stage video channel
		std::uint32_t m_maxStageVideoChannelUsers;

		// approximate number of members in this guild,
		// returned from the GET /guilds/<id> and /users/@me/guilds endpoints when with_counts is true
		std::uint32_t m_approximateMemberCount;

		// approximate number of non-offline members in this guild,
		// returned from the GET /guilds/<id> and /users/@me/guilds endpoints when with_counts is true
		std::uint32_t m_approximatePresenceCount;

		// the welcome screen of a Community guild, shown to new members, returned in an Invite's guild object
		WelcomeScreen m_welcomeScreen;

		// guild NSFW level
		NSFWLevel m_nsfwLevel;

		// custom guild stickers
		std::vector<StickerObject> m_stickers;

		// whether the guild has the boost progress bar enabled
		bool m_premiumProgressBarEnabled;

		// the id of the channel where admins and moderators of Community
		// guilds receive safety alerts from Discord
		Snowflake m_safetyAlertsChannelID;

    public:
        Guild() noexcept;
        Guild(const rapidjson::Value& value) noexcept;
		Guild(
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
		) noexcept;

		Guild& operator=(const Guild& rhs) noexcept;

		bool operator==(const Guild rhs) const noexcept;
		bool operator!=(const Guild rhs) const noexcept;
    };
}