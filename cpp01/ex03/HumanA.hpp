#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <iostream>
#include <string>

class HumanA {
	private:
		std::string	m_name;
		Weapon&		m_weapon;

	public:
		HumanA(std::string name, Weapon& weapon);
		~HumanA();

		void	attack();
};

#endif