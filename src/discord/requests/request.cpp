#include <discord/requests/request.hpp>
#include <discord/endpoints.hpp>

namespace DiscordPP::Requests {
    DiscordRequest::DiscordRequest(
        const std::string path,
        const RequestMethod method
	) noexcept : m_path(path), m_method(method), m_query("") {}

    std::string DiscordRequest::GetPath() const noexcept { return m_path; }
    RequestMethod DiscordRequest::GetMethod() const noexcept { return m_method; }

    Curl::CurlResponse DiscordRequest::Execute(
        Curl* curl,
        const std::vector<Curl::Header> headers,
        const char* data
    ) const noexcept {
        std::string fullQuery = Endpoints::DISCORD_ENDPOINT + m_path + m_query;
        switch(m_method) {
            case RequestMethod::M_GET:
                return curl->Get(fullQuery.c_str(), headers);
                break;
            case RequestMethod::M_POST:
                return curl->Post(fullQuery.c_str(), headers, data);
                break;
            case RequestMethod::M_DELETE:
                return curl->Delete(fullQuery.c_str(), headers, data);
                break;
            case RequestMethod::M_PATCH:
                return curl->Patch(fullQuery.c_str(), headers, data);
                break;
        }
        return { CURLcode::CURLE_UNKNOWN_OPTION, "" };
    }
}