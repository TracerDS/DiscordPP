#pragma once

#include <curl/curl.h>
#include <vector>
#include <string>

class Curl {
public:
	using Header = std::pair<const char*, std::string>;
	struct CurlResponse {
		CURLcode code;
		std::string data;
	};
protected:
	CURL* m_curl{};
	static bool m_isCurlInitialized;

	CurlResponse Raw (
		const char* url,
		const std::vector<Header> headers = {}
	) noexcept;
public:
	Curl() noexcept;
	~Curl() noexcept;

	CurlResponse Get (
		const char* url,
		const std::vector<Header> headers = {}
	) noexcept;

	CurlResponse Post (
		const char* url,
		const std::vector<Header> headers = {},
		const char* postData = ""
	) noexcept;

	CurlResponse Put (
		const char* url,
		const std::vector<Header> headers = {},
		const char* putData = ""
	) noexcept;

	CurlResponse Patch (
		const char* url,
		const std::vector<Header> headers = {},
		const char* patchData = ""
	) noexcept;

	CurlResponse Delete (
		const char* url,
		const std::vector<Header> headers = {},
		const char* deleteData = ""
	) noexcept;

	static bool IsInitialized() noexcept;
};