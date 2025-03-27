#include "BotToken.h"

#include <fstream>
#include <iostream>

BotToken::BotToken() {
    std::string token;
    std::ifstream checkFile("Boterino.token");
    if(checkFile.is_open()) {
        if (getline(checkFile, token)) {
            checkFile.close();
        }
    }
    checkFile.close();
    if (!token.empty()) {
        botToken = token;
    } else {
        std::ofstream createFile("Boterino.token");
        if (createFile.is_open()) {
            std::cout << "Enter your bot token: ";
            std::cin >> token;
            botToken = token;
            createFile << token;
            createFile.close();
            std::cout << "\nToken saved!\n";
        }
    }
}

std::string BotToken::getToken() {
    return botToken;
}