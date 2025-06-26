#pragma once
#include <string>

class Contact {
 public:
  Contact(std::string& name, std::string& phone, std::string& email);

  std::string GetName() const;
  std::string GetPhoneNumber() const;
  std::string GetEmail() const;

 private:
  std::string name_;
  std::string phone_number_;
  std::string email_;
};
