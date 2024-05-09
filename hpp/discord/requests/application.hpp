#pragma once

#include <discord/requests/request.hpp>

namespace DiscordPP::Requests::Application {
	class GetCurrentApplication : public DiscordRequest {
	public:
		GetCurrentApplication() noexcept;
	};

    class EditCurrentApplication : public DiscordRequest {
	public:
		EditCurrentApplication() noexcept;
	};
}