#pragma once

#include <string>

class BotToken {
private:
    std::string botToken;
    std::string getToken() const;
    std::string createToken() const;
public:
    BotToken();
    std::string getToken() const;
};