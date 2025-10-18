#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include <iostream>
#include "AForm.hpp"

class Intern {
  private:
    static AForm* makeShrubbery(const std::string& target);
    static AForm* makeRobotomy(const std::string& target);
    static AForm* makePresidential(const std::string& target);

  public:
    Intern();
    Intern(const Intern&);
    Intern& operator=(const Intern&);
    ~Intern();

    AForm* makeForm(const std::string& name, const std::string& target) const;
};

#endif
