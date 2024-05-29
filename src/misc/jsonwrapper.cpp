#include <misc/jsonwrapper.hpp>

namespace Utils::Json {
    std::optional<bool> GetBoolSafe(const rapidjson::Value& val) noexcept {
        if (!val.IsBool())
            return {};
        return val.GetBool();
    }

    std::optional<std::int32_t> GetIntSafe(const rapidjson::Value& val) noexcept {
        if (!val.IsInt())
            return {};
        return val.GetInt();
    }

    std::optional<std::int64_t> GetInt64Safe(const rapidjson::Value& val) noexcept {
        if (!val.IsInt64())
            return {};
        return val.GetInt64();
    }

    std::optional<std::uint32_t> GetUintSafe(const rapidjson::Value& val) noexcept {
        if (!val.IsUint())
            return {};
        return val.GetUint();
    }

    std::optional<std::uint64_t> GetUint64Safe(const rapidjson::Value& val) noexcept {
        if (!val.IsUint64())
            return {};
        return val.GetUint64();
    }

    std::optional<float> GetFloatSafe(const rapidjson::Value& val) noexcept {
        if (!val.IsFloat())
            return {};
        return val.GetFloat();
    }

    std::optional<double> GetDoubleSafe(const rapidjson::Value& val) noexcept {
        if (!val.IsDouble())
            return {};
        return val.GetDouble();
    }

    std::optional<std::string> GetStringSafe(const rapidjson::Value& val) noexcept {
        if (!val.IsString())
            return {};
        return val.GetString();
    }

    std::optional<JsonArray> GetArraySafe(const rapidjson::Value& val) noexcept {
        if (!val.IsArray())
            return {};
        return val.GetArray();
    }

    std::optional<JsonObject> GetObjectSafe(const rapidjson::Value& val) noexcept {
        if (!val.IsObject())
            return {};
        return val.GetObject();
    }

    bool GetBool(const rapidjson::Value& val) noexcept {
        return GetBoolSafe(val).value_or(false);
    }
    std::int32_t GetInt(const rapidjson::Value& val) noexcept {
        return GetIntSafe(val).value_or(0);
    }
    std::int64_t GetInt64(const rapidjson::Value& val) noexcept {
        return GetInt64Safe(val).value_or(0);
    }
    std::uint32_t GetUint(const rapidjson::Value& val) noexcept {
        return GetUintSafe(val).value_or(0);
    }
    std::uint64_t GetUint64(const rapidjson::Value& val) noexcept {
        return GetUint64Safe(val).value_or(0);
    }
    float GetFloat(const rapidjson::Value& val) noexcept {
        return GetFloatSafe(val).value_or(0);
    }
    double GetDouble(const rapidjson::Value& val) noexcept {
        return GetDoubleSafe(val).value_or(0);
    }
    std::string GetString(const rapidjson::Value& val) noexcept {
        return GetStringSafe(val).value_or("");
    }
    JsonArray GetArray(const rapidjson::Value& val) noexcept {
        return GetArraySafe(val).value();
    }
    JsonObject GetObject(const rapidjson::Value& val) noexcept {
        return GetObjectSafe(val).value();
    }

}