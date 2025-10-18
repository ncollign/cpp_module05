#ifndef PRESIDENTIAL_PARDON_FORM_HPP
#define PRESIDENTIAL_PARDON_FORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
  private:
    std::string target_;
  protected:
    virtual void doExecute() const;
  public:
    explicit PresidentialPardonForm(const std::string& target);
    virtual ~PresidentialPardonForm();
};

#endif
