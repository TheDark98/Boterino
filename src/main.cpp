// Copyright (C) 2025 Nicolo' Sireti. All rights reserved.
//
// This software is the property of Nicolo' Sireti.  
// Copying, modifying, distributing, or unauthorized use
// is strictly prohibited without the explicit written permission
// of the owner.

#include <iostream>
#include <cpr/cpr.h>
#include <nlohmann/json.hpp>
#include <dpp/dpp.h>
#include "BotToken.h" 

int main() {
  BotToken botToken;

  std::string token = botToken.getToken();

  dpp::cluster bot(token.c_str());

  bot.on_log(dpp::utility::cout_logger());

  bot.on_slashcommand([](const dpp::slashcommand_t& event) {
    if (event.command.get_command_name() == "lobby") {
      event.reply("Creating a lobby...");
      event.thinking();
      event.co_edit_original_response(dpp::message().set_content("Lobby created!"));
    }
  });

  bot.on_ready([&bot](const dpp::ready_t& event) {
    if (dpp::run_once<struct register_bot_commands>()) {
      bot.global_command_create(dpp::slashcommand("lobby", "Create an osu lobby!", bot.me.id));
    }
  });

  bot.start(dpp::st_wait);
  
  return 0;
}