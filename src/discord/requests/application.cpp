#include <discord/requests/application.hpp>
#include <discord/endpoints.hpp>

namespace DiscordPP::Requests::Application {
    GetCurrentApplication::GetCurrentApplication() noexcept
        : DiscordRequest(Endpoints::Application::GetCurrentApplication, RequestMethod::M_GET) {}
        
    EditCurrentApplication::EditCurrentApplication() noexcept
        : DiscordRequest(Endpoints::Application::EditCurrentApplication, RequestMethod::M_PATCH) {}

}