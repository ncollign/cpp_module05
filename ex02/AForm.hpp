#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;

class AForm {
  private:
    const std::string name_;
    bool              isSigned_;
    const int         gradeToSign_;
    const int         gradeToExec_;

  protected:
    virtual void doExecute() const = 0;

  public:
    // Canonical
    AForm(const std::string& name, int gradeToSign, int gradeToExec);
    AForm(const AForm& other);
    AForm& operator=(const AForm& other);
    virtual ~AForm();

    // Getters
    const std::string& getName() const;
    bool               isSigned() const;
    int                getGradeToSign() const;
    int                getGradeToExec() const;

    // Signature + exécution
    void beSigned(const Bureaucrat& b);
    void execute(Bureaucrat const & executor) const;

    // Exceptions
    class GradeTooHighException : public std::exception {
      public: const char* what() const throw();
    };
    class GradeTooLowException : public std::exception {
      public: const char* what() const throw();
    };
    class NotSignedException : public std::exception {
      public: const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif
