#include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource
{
private:
    AMateria* slots[4];

public:
    MateriaSource();
    MateriaSource(const MateriaSource& obj);
    MateriaSource& operator= (const MateriaSource& obj);
    ~MateriaSource();

	virtual void learnMateria(AMateria*);
	virtual AMateria* createMateria(std::string const & type);
};
