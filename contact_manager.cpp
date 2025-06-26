#include "contact_manager.h"

bool ContactManager::IsContactsEmpty() const { return contacts_.empty(); }

void ContactManager::AddContact(const Contact &contact) {
  contacts_.push_back(contact);
}

void ContactManager::DeleteContact(const std::string &name) {
  for (auto it = contacts_.begin(); it != contacts_.end(); ++it) {
    if (it->GetName() == name) {
      contacts_.erase(it);
      std::cout << "Contact deleted: " << name << std::endl;
      return;
    } else {
      throw std::runtime_error("Contact not found: " + name);
    }
  }
}

void ContactManager::DisplayContacts() const {
  for (auto contact : contacts_) {
    std::cout << "Name: " << contact.GetName()
              << ", Phone number: " << contact.GetPhoneNumber()
              << ", Email: " << contact.GetEmail() << std::endl;
  }
}
