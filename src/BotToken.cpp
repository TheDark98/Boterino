#include "BotToken.h"

#include <fstream>
#include <iostream>

BotToken::BotToken() {
    std::string token = getToken();

    if (token.c_str() == "") {
        botToken = createToken();
    } else {
        botToken = token;
    }
}

std::string BotToken::getToken() const {
    std::string line;
    std::ifstream file("Boterino.token");

    if(file.is_open()) {
        if (getline(file, line)) {
            file.close();
            return line;
        }
    }
    file.close();
    
    return "";
}

std::string BotToken::createToken() const {
    std::string token;
    std::ofstream file("Boterino.token");

        if (file.is_open()) {
            std::cout << "Enter your bot token: ";
            std::cin >> token;

            file << token;
            file.close();
            std::cout << "\nToken saved!\n";
        }
    return token;
}

std::string BotToken::getToken() const {
    return botToken;
}