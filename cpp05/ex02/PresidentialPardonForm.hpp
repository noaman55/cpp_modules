#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include <iostream>
#include <fstream>

class PresidentialPardonForm: public AForm
{
private:
    std::string target;

public:
    PresidentialPardonForm();
    PresidentialPardonForm(std::string target);
    PresidentialPardonForm(const PresidentialPardonForm& obj);
    PresidentialPardonForm& operator= (const PresidentialPardonForm& obj);
    ~PresidentialPardonForm();

    void		execute(Bureaucrat const & executor) const;
};

#endif