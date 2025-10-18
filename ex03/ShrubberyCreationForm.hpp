#ifndef SHRUBBERY_CREATION_FORM_HPP
#define SHRUBBERY_CREATION_FORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
  private:
    std::string target_;
  protected:
    virtual void doExecute() const; // crée <target>_shrubbery et écrit des arbres ASCII
  public:
    explicit ShrubberyCreationForm(const std::string& target);
    virtual ~ShrubberyCreationForm();
};

#endif
