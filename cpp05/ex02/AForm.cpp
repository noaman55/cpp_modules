#include "AForm.hpp"
#include <iostream>

AForm::AForm():name("Unknown form"), isSigned(false), signGrade(1), execGrade(1)
{
	std::cout << "Form default constructor has been called" << std::endl;
}

AForm::AForm(const std::string& name, int sign_grade, int exec_grade): name(name), isSigned(false), signGrade(sign_grade), execGrade(exec_grade)
{
	if (sign_grade < 1 || exec_grade < 1)
		throw GradeTooHighException();
	else if (sign_grade > 150 || exec_grade > 150)
		throw GradeTooLowException();
	std::cout << name << "'s constructor has been called" << std::endl;
}

AForm::AForm(const AForm& obj): name(obj.name), signGrade(obj.signGrade), execGrade(obj.execGrade)
{
	isSigned = obj.isSigned;
	std::cout << "Form copy constructor has been called" << std::endl;
}

AForm& AForm::operator= (const AForm& obj)
{
	std::cout << "Form assignment operator has been called" << std::endl;
    if (this != &obj)
    {
		isSigned = obj.isSigned;
    }
    return *this;
}

AForm::~AForm()
{
    std::cout << "Form " << name << "'s destructor has been called" << std::endl;
}

const std::string& AForm::getName() const
{
    return name;
}

bool	AForm::getStatus() const
{
	return isSigned;
}

int	AForm::getSignGrade() const
{
    return signGrade;
}

int	AForm::getExecuteGrade() const
{
    return execGrade;
}

void	AForm::beSigned(Bureaucrat& obj)
{
	if (obj.getGrade() <= signGrade)
		isSigned = true;
	else
		throw GradeTooLowException();
}

std::ostream& operator<< (std::ostream& out, const AForm& obj)
{
    out << "Form '" << obj.getName() << "': sign grade " << obj.getSignGrade()
		<< ", execute grade " << obj.getExecuteGrade() << ", status: "
		<< (obj.getStatus() ? "signed" : "not signed") << std::endl;
    return out;
}