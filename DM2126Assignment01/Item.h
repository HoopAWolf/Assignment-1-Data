#ifndef _ITEM_H_
#define _ITEM_H_

#include "GameObject.h"

class Item : public GameObject
{
public:
	explicit Item(const string &name, const int &durabilityInput)
		: GameObject(name), durability(((durabilityInput < 0) ? 0 : durabilityInput))
	{};

	virtual ~Item();

	virtual void receiveDamage(const int &) = 0;
	virtual const int getDurability() const;

private:
	int durability;
};

#endif