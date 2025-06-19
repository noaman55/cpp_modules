#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include "Bureaucrat.hpp"

class AForm
{
private:
    const std::string	name;
    bool				isSigned;
	const int			signGrade;
	const int			execGrade;

public:
    AForm();
	AForm(const std::string& name, int sign_grade, int exec_grade);
	AForm(const AForm& obj);
	AForm& operator= (const AForm& obj);
    ~AForm();

	const std::string&	getName() const;
	bool				getStatus() const;
	int					getSignGrade() const;
	int					getExecGrade() const;
	void				beSigned(Bureaucrat& obj);
	virtual void		execute(Bureaucrat const & executor) const = 0;

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

std::ostream& operator<< (std::ostream& out, const AForm& obj);
#endif