#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
  : AForm("PresidentialPardon", 25, 5), target_(target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::doExecute() const {
	std::cout << target_ << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
