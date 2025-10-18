#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(const std::string& name, int gSign, int gExec)
  : name_(name), isSigned_(false), gradeToSign_(gSign), gradeToExec_(gExec) {
	if (gSign < 1 || gExec < 1)
		throw GradeTooHighException();
	if (gSign > 150 || gExec > 150)
		throw GradeTooLowException();
  }

AForm::AForm(const AForm& o)
  : name_(o.name_), isSigned_(o.isSigned_),
    gradeToSign_(o.gradeToSign_), gradeToExec_(o.gradeToExec_) {}

AForm& AForm::operator=(const AForm& o) {
  if (this != &o) { this->isSigned_ = o.isSigned_; }
  return *this;
}

AForm::~AForm() {}

const std::string& AForm::getName() const { return name_; }
bool AForm::isSigned() const { return isSigned_; }
int AForm::getGradeToSign() const { return gradeToSign_; }
int AForm::getGradeToExec() const { return gradeToExec_; }

void AForm::beSigned(const Bureaucrat& b) {
	if (b.getGrade() <= gradeToSign_)
		isSigned_ = true;
	else
		throw GradeTooLowException();
}

void AForm::execute(Bureaucrat const & executor) const {
	if (!isSigned_)
		throw NotSignedException();
	if (executor.getGrade() > gradeToExec_)
		throw GradeTooLowException();
	else
		doExecute();
}

// Exceptions
const char* AForm::GradeTooHighException::what() const throw() { return "AForm: grade too high"; }
const char* AForm::GradeTooLowException::what() const throw()  { return "AForm: grade too low"; }
const char* AForm::NotSignedException::what() const throw()    { return "AForm: not signed"; }

std::ostream& operator<<(std::ostream& os, const AForm& f) {
  os << "AForm \"" << f.getName() << "\" [signed=" << (f.isSigned() ? "yes":"no")
     << ", gSign=" << f.getGradeToSign() << ", gExec=" << f.getGradeToExec() << "]";
  return os;
}
