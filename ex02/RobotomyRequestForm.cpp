#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
  : AForm("RobotomyRequest", 72, 45), target_(target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::doExecute() const {
	std::srand(std::time(0));
	std::cout << "* drilling noises *" << std::endl;
	if (std::rand() % 2)
		std::cout << target_ << " has been robotomized successfully" << std::endl;
	else
		std::cout << "Robotomy failed on " << target_ << "..." << std::endl;
}
