#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
private:
    
public:
    Intern();
    Intern(const Intern& obj);
    Intern& operator= (const Intern& obj);
    ~Intern();
    AForm* makeForm(std::string form, std::string target);
};

#endif