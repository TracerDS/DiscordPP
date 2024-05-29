#pragma once

#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"

#include <string>
#include <optional>

namespace Utils::Json {
    using JsonArray = rapidjson::GenericArray<true, rapidjson::Value>;
    using JsonObject = rapidjson::GenericObject<true, rapidjson::Value>;

    std::optional<bool> GetBoolSafe(const rapidjson::Value& val) noexcept;
    std::optional<std::int32_t> GetIntSafe(const rapidjson::Value& val) noexcept;
    std::optional<std::int64_t> GetInt64Safe(const rapidjson::Value& val) noexcept;
    std::optional<std::uint32_t> GetUintSafe(const rapidjson::Value& val) noexcept;
    std::optional<std::uint64_t> GetUint64Safe(const rapidjson::Value& val) noexcept;
    std::optional<float> GetFloatSafe(const rapidjson::Value& val) noexcept;
    std::optional<double> GetDoubleSafe(const rapidjson::Value& val) noexcept;
    std::optional<std::string> GetStringSafe(const rapidjson::Value& val) noexcept;
    std::optional<JsonArray> GetArraySafe(const rapidjson::Value& val) noexcept;
    std::optional<JsonObject> GetObjectSafe(const rapidjson::Value& val) noexcept;

    bool GetBool(const rapidjson::Value& val) noexcept;
    std::int32_t GetInt(const rapidjson::Value& val) noexcept;
    std::int64_t GetInt64(const rapidjson::Value& val) noexcept;
    std::uint32_t GetUint(const rapidjson::Value& val) noexcept;
    std::uint64_t GetUint64(const rapidjson::Value& val) noexcept;
    float GetFloat(const rapidjson::Value& val) noexcept;
    double GetDouble(const rapidjson::Value& val) noexcept;
    std::string GetString(const rapidjson::Value& val) noexcept;
    JsonArray GetArray(const rapidjson::Value& val) noexcept;
    JsonObject GetObject(const rapidjson::Value& val) noexcept;

    inline bool SetProperty(void* to, const char* name, const rapidjson::Value& val) noexcept {
        if (val.HasMember(name)) {

        }
        return false;
    }
}