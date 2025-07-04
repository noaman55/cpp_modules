#include "Form.hpp"
#include <iostream>

Form::Form():name("Unknown form"), isSigned(false), signGrade(1), execGrade(1)
{
	std::cout << "Form default constructor has been called" << std::endl;
}

Form::Form(const std::string& name, int s_grade, int e_grade): name(name), isSigned(false), signGrade(s_grade), execGrade(e_grade)
{
	if (s_grade < 1 || e_grade < 1)
		throw GradeTooHighException();
	else if (s_grade > 150 || e_grade > 150)
		throw GradeTooLowException();
	std::cout << name << "'s constructor has been called" << std::endl;
}

Form::Form(const Form& obj): name(obj.name), signGrade(obj.signGrade), execGrade(obj.execGrade)
{
	isSigned = obj.isSigned;
	std::cout << "Form copy constructor has been called" << std::endl;
}

Form& Form::operator= (const Form& obj)
{
	std::cout << "Form assignment operator has been called" << std::endl;
    if (this != &obj)
    {
		isSigned = obj.isSigned;
    }
    return *this;
}

Form::~Form()
{
    std::cout << name << "'s destructor has been called" << std::endl;
}

const std::string& Form::getName() const
{
    return name;
}

bool	Form::getStatus() const
{
	return isSigned;
}

int	Form::getSignGrade() const
{
    return signGrade;
}

int	Form::getExecuteGrade() const
{
    return execGrade;
}

void	Form::beSigned(Bureaucrat& obj)
{
	if (obj.getGrade() <= signGrade)
		isSigned = true;
	else
		throw GradeTooLowException();
}

std::ostream& operator<< (std::ostream& out, const Form& obj)
{
    out << obj.getName() << ": sign grade " << obj.getSignGrade()
		<< ", execute grade " << obj.getExecuteGrade() << ", status: "
		<< (obj.getStatus() ? "signed" : "not signed") << std::endl;
    return out;
}