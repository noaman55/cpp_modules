#include "Character.hpp"

Character::Character(): Name("unknown")
{
	head.content = NULL;
	head.next = NULL;
	for (int i = 0; i < 4; i++)
		slots[i] = NULL;
}

Character::Character(std::string Name): Name(Name)
{
	head.content = NULL;
	head.next = NULL;
	for (int i = 0; i < 4; i++)
		slots[i] = NULL;
}
Character::Character (const Character& obj)
{
	this->Name = obj.Name;
	for (int i = 0; i < 4; i++)
		delete slots[i];
	for (int i = 0; i < 4; i++)
		slots[i] = obj.slots[i]->clone();
}

Character& Character::operator= (const Character& obj)
{
    if (this != &obj)
	{
		this->Name = obj.Name;
		for (int i = 0; i < 4; i++)
			delete slots[i];
		for (int i = 0; i < 4; i++)
			slots[i] = obj.slots[i]->clone();
	}
    return *this;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
		delete slots[i];
}

    
std::string const & Character::getName() const
{
    return Name;
}

void Character::equip(AMateria* m)
{
	// if (m == NULL)
	// {
	// 	std::cout << "Unknown Materia" << std::endl;
	// 	return ;
	// }

    for (int i = 0; i < 4; i++)
	{
		if (slots[i] == NULL)
		{
			slots[i] = m;
			return ;
		}	
	}
	std::cout << "Inventory is full" << std::endl;
}

void Character::lst_addBack(Garbage_coll *head, AMateria* value)
{
	Garbage_coll *ptr = head;

	while (ptr->next != NULL)
		ptr = ptr->next;
	if (ptr->next == NULL)
	{
		head->content = value;
		return ;
	}
	ptr->next = new Garbage_coll;
	ptr->next->content = value;
	ptr->next->next = NULL;
}

void Character::unequip(int idx)
{
	if (!(0 <= idx && idx < 4))
	{
		std::cout << "Invalid index" << std::endl;
		return ;
	}
    if (slots[idx] != NULL)
	{
		lst_addBack(&head, slots[idx]);
		slots[idx] = NULL;
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (!(0 <= idx && idx < 4))
	{
		std::cout << "Invalid index" << std::endl;
		return ;
	}
	if (slots[idx])
		slots[idx]-> use(target);
}


// AMateria* Character::get_slots()
// {
//     return slots[0];
// }