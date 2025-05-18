#ifndef CURE_HPP
#define CURE_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"
#include <string>

class Cure: public AMateria
{
public:
	Cure();
	Cure(const Cure& obj);
    Cure& operator= (const Cure& obj);
	~Cure();
	
	virtual AMateria* clone() const;
	virtual void use(ICharacter& target); // not implemented yet
};

#endif