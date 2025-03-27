#pragma once

#include <string>

class BotToken {
private:
    std::string botToken;
public:
    BotToken();
    std::string getToken();
};