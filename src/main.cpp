#include <cstdio>
#include <iostream>
#include <string>

#include <discord/snowflake.hpp>
#include <misc/curlwrapper.hpp>

#include <discord/requests/user.hpp>
#include <discord/requests/application.hpp>

#include <discord/application.hpp>

#include <discord/endpoints.hpp>

int main() {
    auto tokenEnv = std::getenv("TOKEN");
    std::string token = tokenEnv ? tokenEnv : "None";
    Curl curl;
    auto res = curl.Get(
        (DiscordPP::Endpoints::DISCORD_ENDPOINT + "/voice/regions").c_str(),
        { {"Authorization", ("Bot " + token).c_str()}});
    if (res.code == CURLE_OK) {
        std::cout << res.data << std::endl;
    }

    DiscordPP::Application app;    
    app.login(token.c_str());
    

    return 0;
}