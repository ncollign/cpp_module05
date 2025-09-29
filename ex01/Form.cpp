#include "Form.hpp"
#include "Bureaucrat.hpp"

// Ctor
Form::Form(const std::string& name, int gradeToSign, int gradeToExecute)
  : name_(name), isSigned_(false),
    gradeToSign_(gradeToSign), gradeToExecute_(gradeToExecute) {
  if (gradeToSign < 1 || gradeToExecute < 1){
	throw GradeTooHighException();
  }
  if (gradeToSign > 150 || gradeToExecute > 150) {
	throw GradeTooLowException();
  }
}

// Canonical
Form::Form(const Form& other)
  : name_(other.name_),
    isSigned_(other.isSigned_),
    gradeToSign_(other.gradeToSign_),
    gradeToExecute_(other.gradeToExecute_) {}

Form& Form::operator=(const Form& other) {
  if (this != &other) {
    this->isSigned_ = other.isSigned_;
    // les const (name_, grades) ne sont pas réassignables
  }
  return *this;
}

Form::~Form() {}

// Getters
const std::string& Form::getName() const { return name_; }
bool Form::isSigned() const { return isSigned_; }
int Form::getGradeToSign() const { return gradeToSign_; }
int Form::getGradeToExecute() const { return gradeToExecute_; }

// beSigned (à compléter)
void Form::beSigned(const Bureaucrat& b) {
  if (b.getGrade() > gradeToSign_) {
	throw GradeTooLowException();
  }
  isSigned_ = true;
}

// Exceptions
const char* Form::GradeTooHighException::what() const throw() {
  return "Form: grade too high";
}
const char* Form::GradeTooLowException::what() const throw() {
  return "Form: grade too low";
}

// operator<<
std::ostream& operator<<(std::ostream& os, const Form& f) {
  os << "Form \"" << f.getName() << "\" [signed=" << (f.isSigned() ? "yes" : "no")
     << ", gradeToSign=" << f.getGradeToSign()
     << ", gradeToExecute=" << f.getGradeToExecute() << "]";
  return os;
}
