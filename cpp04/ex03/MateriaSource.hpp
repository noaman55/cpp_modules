#include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource
{
private:
    AMateria* slots[4];

public:
    MateriaSource();
    MateriaSource(const AMateria& obj);
    MateriaSource& operator= (const AMateria& obj);
    ~MateriaSource();

	virtual void learnMateria(AMateria*);
	virtual AMateria* createMateria(std::string const & type);
};
