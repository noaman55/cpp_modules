#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>

class RobotomyRequestForm: public AForm
{
private:
    std::string target;

public:
    RobotomyRequestForm();
    RobotomyRequestForm(std::string target);
    RobotomyRequestForm(const RobotomyRequestForm& obj);
    RobotomyRequestForm& operator= (const RobotomyRequestForm& obj);
    ~RobotomyRequestForm();

    void		execute(Bureaucrat const & executor) const;
};

#endif