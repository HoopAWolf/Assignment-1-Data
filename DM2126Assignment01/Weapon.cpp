#include "Weapon.h"

Weapon::~Weapon()
{
	;
}

const int &Weapon::getAttackDmg() const
{
	return this->kAttackDmg;
}
