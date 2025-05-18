#include "AMateria.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

// int main()
// {
// 	IMateriaSource* src = new MateriaSource();
// 	src->learnMateria(new Ice());
// 	src->learnMateria(new Cure());

// 	ICharacter* me = new Character("me");

// 	AMateria* tmp;
// 	tmp = src->createMateria("ice");
// 	me->equip(tmp);
// 	tmp = src->createMateria("cure");
// 	me->equip(tmp);

// 	ICharacter* bob = new Character("bob");

// 	me->use(0, *bob);
// 	me->use(1, *bob);

// 	delete bob;
// 	delete me;
// 	delete src;

// 	return 0;
// }


int main() {
    std::cout << "=== Creating Materia Source ===" << std::endl;
    IMateriaSource* src = new MateriaSource();

    std::cout << "=== Learning Materias ===" << std::endl;
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    std::cout << "=== Creating Character ===" << std::endl;
    ICharacter* me = new Character("Player");
	
    std::cout << "=== Creating Materias ===" << std::endl;
    AMateria* tmp1 = src->createMateria("ice");
    AMateria* tmp2 = src->createMateria("cure");
    AMateria* tmp3 = src->createMateria("fire"); // unknown
	
	
    std::cout << "=== Equipping Materias ===" << std::endl;
    me->equip(tmp1); // equip ice
    me->equip(tmp2); // equip cure
    me->equip(NULL); // do nothing
    me->equip(tmp3); // do nothing (fire unknown)
	
    std::cout << "=== Using Materias ===" << std::endl;
    ICharacter* bob = new Character("Bob");
    me->use(0, *bob); // ice
    me->use(1, *bob); // cure
    me->use(2, *bob); // nothing
    me->use(3, *bob); // nothing
    me->use(4, *bob); // out of bounds
	
    std::cout << "=== Unequipping Slot 0 ===" << std::endl;
    me->unequip(0); // don't delete materia!
    // keep a manual reference to tmp1 if needed (to delete later)
	
	
	std::cout << "\n\n\n\n mmmmmmmmmmmmm \n\n\n\n" << std::endl;
    std::cout << "=== Copying Character ===" << std::endl;
    Character* copy = new Character(*dynamic_cast<Character*>(me));
    std::cout << "=== Using Copy ===" << std::endl;
    copy->use(1, *bob); // should be cure (deep copied)
    copy->use(0, *bob); // should be empty if slot 0 was unequipped
	

    std::cout << "=== Equipping more than 4 Materias ===" << std::endl;
    copy->equip(new Ice());
    copy->equip(new Ice());
    copy->equip(new Ice()); // should fill up to 4
    copy->equip(new Ice()); // should be ignored

    std::cout << "=== Testing Unequip Bounds ===" << std::endl;
    copy->unequip(10); // should do nothing
    copy->unequip(-1); // should do nothing

    std::cout << "=== Cleaning up ===" << std::endl;
    delete src;
    delete me;
    delete bob;
    delete copy;

    // cleanup unequipped materia to avoid leak
    delete tmp1;
    delete tmp3;

    return 0;
}