#include "Character.hpp"

Character::Character(): Name("Unknown")
{
	head = new Garbage_coll;
	head->content = NULL;
	head->next = NULL;
	for (int i = 0; i < 4; i++)
		slots[i] = NULL;
}

Character::Character(std::string Name): Name(Name)
{
	head = new Garbage_coll;
	head->content = NULL;
	head->next = NULL;
	for (int i = 0; i < 4; i++)
		slots[i] = NULL;
}

Character::Character (const Character& obj)
{
	head = new Garbage_coll;
	head->content = NULL;
	head->next = NULL;
	this->Name = obj.Name;

	for (int i = 0; i < 4; ++i) {
		if (obj.slots[i])
			slots[i] = obj.slots[i]->clone();
		else
			slots[i] = NULL;
	}
}

Character& Character::operator= (const Character& obj)
{
    if (this != &obj)
	{
		this->Name = obj.Name;
		for (int i = 0; i < 4; i++)
		{
			delete slots[i];
			slots[i] = NULL;
		}
		for (int i = 0; i < 4; i++)
			slots[i] = obj.slots[i]->clone();
	}
    return *this;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		delete slots[i];
		slots[i] = NULL;
	}
	lst_clear(&head);
}
    
std::string const & Character::getName() const
{
    return Name;
}

void Character::equip(AMateria* m)
{
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

void Character::lst_clear(Garbage_coll **head)
{
	Garbage_coll *tmp = *head;

	if (!head || !*head)
		return ;

	while (tmp)
	{
		*head = (*head)->next;
		delete tmp->content;
		delete tmp;
		tmp = *head;
	}
}

void Character::lst_addBack(Garbage_coll *head, AMateria* value)
{
	Garbage_coll *ptr = head;

	if (head == NULL)
	{
		std::cout << "head is NULLLLLLLLLLLLLLLLL" << std::endl;
		return ;
	}
	if (ptr->content == NULL)
	{
		ptr->content = value;
		return ;
	}
	while (ptr->next != NULL)
		ptr = ptr->next;
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
		lst_addBack(head, slots[idx]);
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