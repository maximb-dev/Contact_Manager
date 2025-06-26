#pragma once
#include <regex>

#include "contact_manager.h"

class UserInterface {
 public:
  void HandleUserInput(ContactManager& manager);
 private:
  void DisplayMenu() const;
  bool IsValidEmail(const std::string& email);
  bool IsValidPhoneNumber(const std::string& phone_number);
};
