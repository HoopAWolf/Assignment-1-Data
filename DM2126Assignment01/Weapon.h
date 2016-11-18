#ifndef _WEAPON_H_
#define _WEAPON_H_

#include "Item.h"

class Weapon : public Item
{
public:
	Weapon(const string &nameInput, const int &durabilityInput, const int &damageInput)
		: Item(nameInput, ((durabilityInput < 0) ? 0 : durabilityInput)), kAttackDmg(((damageInput < 0) ? 0 : damageInput))
	{};

	~Weapon();

	const int &getAttackDmg() const;

	virtual void receiveDamage(const int &damageInput)
	{
		Item::receiveDamage(damageInput);
	}

private:
	const int kAttackDmg;
};

#endif