#include "Item.h"

Item::~Item()
{
	;
}

void Item::receiveDamage(const int &damageInput)
{
	this->durability -= damageInput;
}

const int Item::getDurability() const
{
	return this->durability;
}