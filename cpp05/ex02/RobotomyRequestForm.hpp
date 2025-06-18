#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm: public AForm
{
private:
    
public:
    RobotomyRequestForm(/* args */);
    RobotomyRequestForm(const RobotomyRequestForm& obj);
    RobotomyRequestForm& operator= (const RobotomyRequestForm& obj);
    ~RobotomyRequestForm();

    void		execute(Bureaucrat const & executor) const;
};




#endif