#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "AMateria.hpp"

struct Garbage_coll
{
	AMateria* content;
	Garbage_coll* next;

};

class Character:public ICharacter
{
private:
    std::string Name;
    AMateria* slots[4];
	Garbage_coll head;

public:
    Character();
    Character(std::string Name);
	Character (const Character& obj);
	Character& operator= (const Character& obj);
	virtual ~Character();

	virtual std::string const & getName() const;
	virtual void equip(AMateria* m);
	virtual void unequip(int idx);
	virtual void use(int idx, ICharacter& target);
	void lst_addBack(Garbage_coll *head, AMateria* value);
	// AMateria* get_slots();
};



#endif