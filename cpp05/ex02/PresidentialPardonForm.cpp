#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("PresidentialPardonForm", 25, 5), target("Unknown")
{
    std::cout << "PresidentialPardonForm default constructor has been called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("PresidentialPardonForm", 25, 5), target(target)
{
    std::cout << "PresidentialPardonForm constructor has been called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& obj)
{
    *this = obj;
}

PresidentialPardonForm& PresidentialPardonForm::operator= (const PresidentialPardonForm& obj)
{
    std::cout << "PresidentialPardonForm assignment operator has been called" << std::endl;
    if (this != &obj)
    {
        target = obj.target;
    }
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "PresidentialPardonForm destructor has been called" << std::endl;
}

void    PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    if (getStatus() && executor.getGrade() <= getExecGrade())
    {
        std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
    }
}