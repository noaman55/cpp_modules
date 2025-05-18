#ifndef AMETRIA_HPP
#define AMETRIA_HPP

#include "ICharacter.hpp"
#include <iostream>
#include <string>

class AMateria
{
protected:
	std::string type;
public:
	AMateria();
	AMateria(std::string const & type);
	AMateria(const AMateria& obj);
	AMateria& operator= (const AMateria& obj);
	virtual ~AMateria();

	std::string const & getType() const;
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};

#endif