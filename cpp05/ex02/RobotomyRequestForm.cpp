#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm", 72, 45), target("Unknown")
{
    std::cout << "RobotomyRequestForm default constructor has been called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("RobotomyRequestForm", 72, 45), target(target)
{
    std::cout << "RobotomyRequestForm constructor has been called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& obj)
{
    *this = obj;
}

RobotomyRequestForm& RobotomyRequestForm::operator= (const RobotomyRequestForm& obj)
{
    std::cout << "RobotomyRequestForm assignment operator has been called" << std::endl;
    if (this != &obj)
    {
        target = obj.target;
    }
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "RobotomyRequestForm destructor has been called" << std::endl;
}

void    RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    if (getStatus() && executor.getGrade() <= getExecGrade())
    {
        std::cout << "Bzzzzzz... Vrrrrrrr... Drrrrr!!!" << std::endl;
        srand(time(0));
        if (rand() % 2 == 0)
            std::cout << target << " has been robotomized successfully" << std::endl;
        else
            std::cout << "Robotomy failed on " << target << std::endl;
    }
}