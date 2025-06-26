#include "contact.h"

Contact::Contact(std::string& name, std::string& phone_number,
                 std::string& email)
    : name_(name), phone_number_(phone_number), email_(email) {}

std::string Contact::GetEmail() const { return email_; }

std::string Contact::GetName() const { return name_; }

std::string Contact::GetPhoneNumber() const { return phone_number_; }
