#pragma once

#include <string>
#include <misc/curlwrapper.hpp>

namespace DiscordPP::Requests {
	enum class RequestMethod {
		M_GET,
		M_HEAD,
		M_POST,
		M_PUT,
		M_DELETE,
		M_CONNECT,
		M_OPTIONS,
		M_TRACE,
		M_PATCH
	};
	
	class DiscordRequest {
	protected:
		std::string m_path;
		RequestMethod m_method;

		std::string m_query;
	public:
		DiscordRequest(
			const std::string path,
			const RequestMethod method
		) noexcept;

		std::string GetPath() const noexcept;
		RequestMethod GetMethod() const noexcept;

		Curl::CurlResponse Execute (
			Curl* curl,
			const std::vector<Curl::Header> headers = {},
			const char* data = ""
		) const noexcept;
	};
}