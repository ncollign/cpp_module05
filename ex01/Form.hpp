#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;

class Form {
  private:
    const std::string name_;
    bool              isSigned_;
    const int         gradeToSign_;
    const int         gradeToExecute_;

  public:
    Form(const std::string& name, int gradeToSign, int gradeToExecute);
    Form(const Form& other);
    Form& operator=(const Form& other);
    ~Form();

    // Getters
    const std::string& getName() const;
    bool               isSigned() const;
    int                getGradeToSign() const;
    int                getGradeToExecute() const;

    // Actions
    void beSigned(const Bureaucrat& b); // implémentation plus tard

    // Exceptions
    class GradeTooHighException : public std::exception {
      public:
        const char* what() const throw();
    };
    class GradeTooLowException : public std::exception {
      public:
        const char* what() const throw();
    };
};

// operator<<
std::ostream& operator<<(std::ostream& os, const Form& f);

#endif
