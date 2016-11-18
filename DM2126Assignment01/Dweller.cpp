#include "Dweller.h"

Dweller::Dweller(const string &nameInput, const int &specialInput) 
: GameObject(nameInput)
{
	int specialInputSub = specialInput;

	for (int i = 0; i < 7; i++)
	{
		if (specialInputSub != 0)
		{
			switch (i)
			{
			case 0:
				L = specialInputSub % 10;
				specialInputSub /= 10;
				break;
			case 1:
				A = specialInputSub % 10;
				specialInputSub /= 10;
				break;
			case 2:
				I = specialInputSub % 10;
				specialInputSub /= 10;
				break;
			case 3:
				C = specialInputSub % 10;
				specialInputSub /= 10;
				break;
			case 4:
				E = specialInputSub % 10;
				specialInputSub /= 10;
				break;
			case 5:
				P = specialInputSub % 10;
				specialInputSub /= 10;
				break;
			case 6:
				S = specialInputSub % 10;
				specialInputSub /= 10;
				break;
			default:
				break;
			}
		}
	}
}

Dweller::~Dweller()
{
	;
}

//////////////////////////GETTERS//////////////////////////
const int Dweller::getSPECIAL() const
{
	int SPECIAL = 0, S = 0, P = 0, E = 0, C = 0, I = 0, A = 0, L = 0, specialInputSub;

	if (outfit != NULL && outfit->getDurability() > 0)
	{
		specialInputSub = outfit->getSPECIAL();
	}
	else
	{
		specialInputSub = 0;
	}

	for (int i = 0; i < 7; i++)
	{
		if (specialInputSub != 0)
		{
			switch (i)
			{
			case 0:
				L = specialInputSub % 10;
				specialInputSub /= 10;
				break;
			case 1:
				A = specialInputSub % 10;
				specialInputSub /= 10;
				break;
			case 2:
				I = specialInputSub % 10;
				specialInputSub /= 10;
				break;
			case 3:
				C = specialInputSub % 10;
				specialInputSub /= 10;
				break;
			case 4:
				E = specialInputSub % 10;
				specialInputSub /= 10;
				break;
			case 5:
				P = specialInputSub % 10;
				specialInputSub /= 10;
				break;
			case 6:
				S = specialInputSub % 10;
				specialInputSub /= 10;
				break;
			default:
				break;
			}
		}
	}

	SPECIAL += (((this->L + L) > 9) ? 9 : this->L + L);
	SPECIAL += (((this->A + A) > 9) ? 9 : this->A + A) * 10;
	SPECIAL += (((this->I + I) > 9) ? 9 : this->I + I) * 100;
	SPECIAL += (((this->C + C) > 9) ? 9 : this->C + C) * 1000;
	SPECIAL += (((this->E + E) > 9) ? 9 : this->E + E) * 10000;
	SPECIAL += (((this->P + P) > 9) ? 9 : this->P + P) * 100000;
	SPECIAL += (((this->S + S) > 9) ? 9 : this->S + S) * 1000000;


	return SPECIAL;
}

const int Dweller::getCurrentHealth() const
{
	return health;
}

const int Dweller::getCurrentRadDamage() const
{
	return radAway;
}

const int Dweller::getAttackDmg() const
{
	if (weapon != NULL && weapon->getDurability() > 0)
	{
		return weapon->getAttackDmg();
	}
	else
	{
		return 1;
	}
}

//////////////////////////POSITION//////////////////////////
void Dweller::setPosition(const Vec2D positionInput)
{
	*position = positionInput;
}

const Vec2D Dweller::getPosition() const
{
	return *position;
}

//////////////////////////RECIEVERS//////////////////////////
void Dweller::receiveHealthDamage(const int &healthDamageInput)
{
	health -= healthDamageInput;
}

void Dweller::receiveRadDamage(const int &radDamageInput)
{
	
}

void Dweller::receiveEquipmentDamage(const int &damageInput)
{
	
}

//////////////////////////ADDERS//////////////////////////
void Dweller::addStimpak(const int &stimpackInput)
{
	stimpack += stimpackInput;
}

void Dweller::addRadAway(const int &radAwayInput)
{
	radAway += radAwayInput;
}

//////////////////////////USE-ERS//////////////////////////
void Dweller::useStimpak()
{
	if (stimpack > 0 && getCurrentHealth() < 100)
	{
		--stimpack;
		health += 20;
	}

	if (getCurrentHealth() > 100)
		health = 100;
}

void Dweller::useRadAway()
{
	if (radAway > 0 && getCurrentRadDamage() > 0)
	{
		--radAway;
		radiation -= 10;
	}

	if (radiation < 0)
		radiation = 0;
}

//////////////////////////ASSIGNERS//////////////////////////
Outfit* Dweller::assignOutfit(Outfit *outfitInput)
{
	this->outfit = outfitInput;

	return this->outfit;
}

Weapon* Dweller::assignWeapon(Weapon *weaponInput)
{
	this->weapon = weaponInput;

	return this->weapon;
}

bool Dweller::isDead()
{
	if (getCurrentHealth() < 1)
		return true;

	return false;
}
