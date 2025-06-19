#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <iostream>
#include <fstream>

class ShrubberyCreationForm: public AForm
{
private:
    std::string target;
    
public:
    
    ShrubberyCreationForm();
    ShrubberyCreationForm(std::string target);
    ShrubberyCreationForm(const ShrubberyCreationForm& obj);
    ShrubberyCreationForm& operator= (const ShrubberyCreationForm& obj);
    ~ShrubberyCreationForm();

    void		execute(Bureaucrat const & executor) const;
};

#endif