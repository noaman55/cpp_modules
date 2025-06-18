#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include "Bureaucrat.hpp"

class Form
{
private:
    const std::string	name;
    bool				status;
	const int			signGrade;
	const int			execGrade;

public:
    Form();
	Form(const std::string& name, int s_grade, int e_grade);
	Form(const Form& obj);
	Form& operator= (const Form& obj);
    ~Form();

	const std::string&	getName() const;
	bool				getStatus() const;
	int					getSignGrade() const;
	int					getExecuteGrade() const;
	void				beSigned(Bureaucrat& obj);

	class GradeTooHighException: public std::exception
	{
		public:
		const char* what() const throw() { return "Grade is too high!"; }
	};

	class GradeTooLowException: public std::exception
	{
		public:
		const char* what() const throw() { return "Grade is too low!"; }
	};
};

std::ostream& operator<< (std::ostream& out, const Form& obj);
#endif