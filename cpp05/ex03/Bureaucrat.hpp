#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <exception>
class AForm;

class Bureaucrat
{
private:
    const std::string	name;
    int					grade;

public:
	Bureaucrat();
	Bureaucrat(const std::string& name, int grade);
	Bureaucrat(const Bureaucrat& obj);
	Bureaucrat& operator= (const Bureaucrat& obj);
    ~Bureaucrat();

	void				incrementGrade();
	void				decrementGrade();
	const std::string&	getName() const;
	int					getGrade() const;
	void				signForm(AForm& obj);
	void				executeForm(AForm const & form);

	class GradeTooHighException: public std::exception
	{
		public:
		const char* what() const throw() { return "Bureaucrat grade is too high!"; }
	};

	class GradeTooLowException: public std::exception
	{
		public:
		const char* what() const throw() { return "Bureaucrat grade is too low!"; }
	};
};

std::ostream& operator<< (std::ostream& out, const Bureaucrat& obj);

#endif