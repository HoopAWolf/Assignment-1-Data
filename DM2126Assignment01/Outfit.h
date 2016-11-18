#ifndef _OUTFIT_H_
#define _OUTFIT_H_

#include "Item.h"

class Outfit : public Item
{
public:
	Outfit(const string &nameInput, const int &durabilityInput, const int &SPECIALInput) 
		: Item(nameInput, ((durabilityInput < 0) ? 0 : durabilityInput)), kSPECIAL(SPECIALInput)
	{};

	~Outfit();

	const int &getSPECIAL() const;

	virtual void receiveDamage(const int &damageInput)
	{
		Item::receiveDamage(damageInput);
	}

private:
	const int kSPECIAL;
};

#endif