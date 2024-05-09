#pragma once

#include <curlwrapper/wrapper.hpp>
#include <utils.hpp>

bool Curl::m_isCurlInitialized = false;

Curl::Curl() noexcept {
    if (!m_isCurlInitialized) {
        CURLcode code = curl_global_init(CURL_GLOBAL_DEFAULT);
        if (code != CURLcode::CURLE_OK) {
            fprintf(stderr, "Cannot initialize global CURL: %s\n", curl_easy_strerror(code));
            return;
        }
    }

    m_curl = curl_easy_init();
    if (!m_curl) {
        fprintf(stderr, "Cannot initialize CURL\n");
        return;
    }

    m_isCurlInitialized = true;

    curl_easy_setopt(m_curl, CURLOPT_HTTP_VERSION, CURL_HTTP_VERSION_2TLS);
    curl_easy_setopt(m_curl, CURLOPT_WRITEFUNCTION,
        +[](const char* ptr, size_t size, size_t nmemb, std::string* s) {
            s->append(ptr, size * nmemb);
            return size * nmemb;
        }
    );
}

Curl::~Curl() noexcept {
    if (m_curl)
        curl_easy_cleanup(m_curl);

    if (m_isCurlInitialized) {
        curl_global_cleanup();
        m_isCurlInitialized = false;
    }
}

Curl::CurlResponse Curl::Raw (
    const char* url,
    const std::vector<Header> headers
) noexcept {
    curl_slist* curlHeaders = nullptr;

    for (const auto& [key, value] : headers) {
        const auto header = Utils::JoinHTTPHeader(key, value);
        curlHeaders = curl_slist_append(curlHeaders, header.c_str());
    }
    curl_easy_setopt(m_curl, CURLOPT_HTTPHEADER, curlHeaders);

    std::string outData{};
    curl_easy_setopt(m_curl, CURLOPT_URL, url);
    curl_easy_setopt(m_curl, CURLOPT_WRITEDATA, &outData);
    
    const auto code = curl_easy_perform(m_curl);
    return { code, outData };
}

Curl::CurlResponse Curl::Get (
    const char* url,
    const std::vector<Header> headers
) noexcept {
    curl_easy_setopt(m_curl, CURLOPT_CUSTOMREQUEST, "GET");
    return Raw(url, headers);
}

Curl::CurlResponse Curl::Post (
    const char* url,
    const std::vector<Header> headers,
    const char* postData
) noexcept {
    curl_easy_setopt(m_curl, CURLOPT_CUSTOMREQUEST, "POST");
    curl_easy_setopt(m_curl, CURLOPT_POSTFIELDS, postData);
    return Raw(url, headers);
}

Curl::CurlResponse Curl::Patch (
    const char* url,
    const std::vector<Header> headers,
    const char* patchData
) noexcept {
    curl_easy_setopt(m_curl, CURLOPT_CUSTOMREQUEST, "PATCH");
    curl_easy_setopt(m_curl, CURLOPT_POSTFIELDS, patchData);
    return Raw(url, headers);
}

Curl::CurlResponse Curl::Put (
    const char* url,
    const std::vector<Header> headers,
    const char* putData
) noexcept {
    curl_easy_setopt(m_curl, CURLOPT_CUSTOMREQUEST, "PUT");
    curl_easy_setopt(m_curl, CURLOPT_POSTFIELDS, putData);
    return Raw(url, headers);
}

Curl::CurlResponse Curl::Delete (
    const char* url,
    const std::vector<Header> headers,
    const char* deleteData
) noexcept {
    curl_easy_setopt(m_curl, CURLOPT_CUSTOMREQUEST, "DELETE");
    curl_easy_setopt(m_curl, CURLOPT_POSTFIELDS, deleteData);
    return Raw(url, headers);
}

bool Curl::IsInitialized() noexcept {
    return m_isCurlInitialized;
}