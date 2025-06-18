#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm: public AForm
{
private:
    
public:
    PresidentialPardonForm(/* args */);
    PresidentialPardonForm(const PresidentialPardonForm& obj);
    PresidentialPardonForm& operator= (const PresidentialPardonForm& obj);
    ~PresidentialPardonForm();

    void		execute(Bureaucrat const & executor) const;
};




#endif