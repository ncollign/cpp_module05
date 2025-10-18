#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

// Canonical
Intern::Intern() {}
Intern::Intern(const Intern&) {}
Intern& Intern::operator=(const Intern&) { return *this; }
Intern::~Intern() {}

// Factories
AForm* Intern::makeShrubbery(const std::string& target) {
    return new ShrubberyCreationForm(target);
}
AForm* Intern::makeRobotomy(const std::string& target) {
    return new RobotomyRequestForm(target);
}
AForm* Intern::makePresidential(const std::string& target) {
    return new PresidentialPardonForm(target);
}

// Table de correspondance: nom -> factory
AForm* Intern::makeForm(const std::string& name, const std::string& target) const {
    struct Entry { const char* key; AForm* (*factory)(const std::string&); };
    static const Entry table[3] = {
        { "shrubbery creation",  &Intern::makeShrubbery },
        { "robotomy request",    &Intern::makeRobotomy },
        { "presidential pardon", &Intern::makePresidential }
    };

    for (int i = 0; i < 3; ++i) {
        if (name == table[i].key) {
            std::cout << "Intern creates " << name << std::endl;
            return table[i].factory(target);
        }
    }
    std::cout << "Intern: unknown form name \"" << name << "\"" << std::endl;
    return 0;
}
