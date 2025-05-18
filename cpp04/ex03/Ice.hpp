#ifndef ICE_HPP
#define ICE_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"
#include <string>

class Ice: public AMateria
{
public:
	Ice();
	Ice(const Ice& obj);
	Ice& operator= (const Ice& obj);
	~Ice();

	virtual AMateria* clone() const;
	virtual void use(ICharacter& target);
};

#endif