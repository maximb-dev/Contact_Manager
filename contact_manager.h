#pragma once
#include <cstdint>
#include <iostream>
#include <stdexcept>
#include <vector>

#include "contact.h"

class ContactManager {
 public:
  void AddContact(const Contact& contact);
  void DeleteContact(const std::string& name);
  void DisplayContacts() const;
  bool IsContactsEmpty() const;

 private:
  std::vector<Contact> contacts_;
};
