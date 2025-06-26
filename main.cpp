#include "user_interface.h"

int main() {
  UserInterface ui;
  ContactManager manager;

  try {
    ui.HandleUserInput(manager);
  } catch (std::runtime_error& e) {
    std::cerr << "An error occurred: " << e.what() << std::endl;
  }

  return 0;
}