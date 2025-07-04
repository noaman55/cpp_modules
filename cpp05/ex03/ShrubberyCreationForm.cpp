#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyCreationForm", 145, 137), target("Unknown")
{
    std::cout << "ShrubberyCreationForm default constructor has been called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("ShrubberyCreationForm", 145, 137), target(target)
{
    // std::cout << "ShrubberyCreationForm constructor has been called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& obj): AForm(obj), target(obj.target)
{
    std::cout << "ShrubberyCreationForm copy constructor has been called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator= (const ShrubberyCreationForm& obj)
{
    std::cout << "ShrubberyCreationForm assignment operator has been called" << std::endl;
    if (this != &obj)
    {
        target = obj.target;
    }
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    // std::cout << "ShrubberyCreationForm destructor has been called" << std::endl;
}

void    ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    if (getStatus() && executor.getGrade() <= getExecGrade())
    {
        std::ofstream outfile((target + "_shrubbery").c_str());
        if (!outfile)
        {
            throw std::runtime_error("can't open the shrubbery file");
        }
        outfile << "       /\\       " << std::endl;
        outfile << "      /\\*\\      " << std::endl;
        outfile << "     /\\O\\*\\     " << std::endl;
        outfile << "    /*/\\/\\/\\    " << std::endl;
        outfile << "   /\\O\\/\\*\\/\\   " << std::endl;
        outfile << "  /\\*\\/\\*\\/\\/\\  " << std::endl;
        outfile << " /\\O\\/\\/*/\\/O/\\ " << std::endl;
        outfile << "       ||       " << std::endl;
        outfile << "       ||       " << std::endl;
        outfile << "       ||       " << std::endl;
        outfile.close();
    }
    else
    {
        throw "can't execute the form because it's not signed or the executor grade is not high enough";
    }
}