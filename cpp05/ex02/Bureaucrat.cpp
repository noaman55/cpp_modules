#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

Bureaucrat::Bureaucrat()
{
	std::cout << "Bureaucrat default constructor has been called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade_val): name(name)
{
    if (grade_val < 1)
        throw GradeTooHighException();
    else if (grade_val > 150)
        throw GradeTooLowException();
    else
        grade = grade_val;
    std::cout << "Bureaucrat " << name << "'s constructor has been called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& obj):name(obj.name), grade(obj.grade)
{
	std::cout << "Bureaucrat copy constructor has been called" << std::endl;
}

Bureaucrat& Bureaucrat::operator= (const Bureaucrat& obj)
{
    if (this != &obj)
    {
    }
    return (*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor has been called" << std::endl;
}

void	Bureaucrat::incrementGrade()
{
	if (grade == 1)
		throw Bureaucrat::GradeTooHighException();
	else
		grade -= 1;
}

void	Bureaucrat::decrementGrade()
{
	if (grade == 150)
		throw Bureaucrat::GradeTooLowException();
	else
		grade += 1;
}

const std::string& Bureaucrat::getName() const
{
    return name;
}

int Bureaucrat::getGrade() const
{
    return grade;
}

void	Bureaucrat::signForm(Form& obj)
{
	obj.beSigned(*this);
	if (obj.getStatus())
		std::cout << name << " signed " << obj.getName() << std::endl;
	else
	std::cout << name << "lllllllllllllllllllll couldn’t sign " << obj.getName() << "because grade too low." << std::endl;
}

std::ostream& operator<< (std::ostream& out, const Bureaucrat& obj)
{
    out << obj.getName();
    std::cout << ", bureaucrat grade ";
    std::cout << obj.getGrade() << ".";
    return out;
}
