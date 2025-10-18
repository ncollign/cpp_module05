#ifndef ROBOTOMY_REQUEST_FORM_HPP
#define ROBOTOMY_REQUEST_FORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
  private:
    std::string target_;
  protected:
    virtual void doExecute() const; // bruit + 50% réussite
  public:
    explicit RobotomyRequestForm(const std::string& target);
    virtual ~RobotomyRequestForm();
};

#endif
