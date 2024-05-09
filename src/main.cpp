#include <cstdio>
#include <iostream>
#include <string>

#include <discord/snowflake.hpp>

#include <misc/curlwrapper.hpp>

#include <discord/requests/user.hpp>
#include <discord/client.hpp>
#include <discord/requests/application.hpp>

int main() {
    Curl curl;
    DiscordPP::Client client;
    
    auto token = std::getenv("TOKEN");
    auto res = client.login(token ? token : "None");

    return 0;
}