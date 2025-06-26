#include "user_interface.h"

bool UserInterface::IsValidEmail(const std::string &email) {
  const std::regex pattern(R"((\w+)(\.|_)?(\w*)@(\w+)\.(\w+))");
  return std::regex_match(email, pattern);
}

bool UserInterface::IsValidPhoneNumber(const std::string &phone_number) {
  const std::regex pattern(R"(\+\d{10,15})");
  return std::regex_match(phone_number, pattern);
}

void UserInterface::DisplayMenu() const {
  std::cout << "1. Add Contacts\n";
  std::cout << "2. Delete Contact\n";
  std::cout << "3. View Contacts\n";
  std::cout << "4. Exit\n";
}

void UserInterface::HandleUserInput(ContactManager &manager) {
  int choice;
  std::string name, phoneNumber, email;

  while (true) {
    DisplayMenu();
    std::cout << "Choose an option: ";
    std::cin >> choice;

    switch (choice) {
      case 1: {
        std::cout << "Enter name: ";
        std::cin >> name;
        do {
          std::cout << "Enter phone number: ";
          std::cin >> phoneNumber;
          if (!IsValidPhoneNumber(phoneNumber)) {
            std::cout << "Invalid phone number format. Please try again. \n";
          }
        } while (!IsValidPhoneNumber(phoneNumber));

        do {
          std::cout << "Enter email: ";
          std::cin >> email;
          if (!IsValidEmail(email)) {
            std::cout << "Invalid email. Please try again. \n";
          }
        } while (!IsValidEmail(email));

        manager.AddContact(Contact{name, phoneNumber, email});
        break;
      }
      case 2: {
        if (manager.IsContactsEmpty()) {
          std::cout << "No contacts\n";
          break;
        }
        std::cout << "Enter name to delete: ";
        std::cin >> name;
        manager.DeleteContact(name);
        break;
      }
      case 3:{
        if (manager.IsContactsEmpty()) {
          std::cout << "No contacts\n";
        }
        manager.DisplayContacts();
        break;
      }
      case 4: {
        std::cout << "Goodbye";
        return;
      }
      default: {
        std::cout << "Invalid option. Please try again\n";
      }
    }
  }
}
