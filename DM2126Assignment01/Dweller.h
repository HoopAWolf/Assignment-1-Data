#ifndef _DWELLER_H_
#define _DWELLER_H_

#include "Vec2D.h"
#include "GameObject.h"
#include "Outfit.h"
#include "Weapon.h"

class Dweller : public GameObject
{
public:

	Dweller(const string &, const int &);
	~Dweller();

	//////////////////////////GETTERS//////////////////////////
	const int getSPECIAL() const;
	const int getCurrentHealth() const;
	const int getCurrentRadDamage() const;
	const int getAttackDmg() const;

	//////////////////////////POSITION//////////////////////////
	void setPosition(const Vec2D);
	const Vec2D getPosition() const;

	//////////////////////////RECIEVERS//////////////////////////
	void receiveHealthDamage(const int &);
	void receiveRadDamage(const int &);
	void receiveEquipmentDamage(const int &);

	//////////////////////////ADDERS//////////////////////////
	void addStimpak(const int &);
	void addRadAway(const int &);

	//////////////////////////USE-ERS//////////////////////////
	void useStimpak();
	void useRadAway();

	//////////////////////////ASSIGNERS//////////////////////////
	Outfit* assignOutfit(Outfit *);
	Weapon * assignWeapon(Weapon *);

	bool isDead();
	

private:
	int 
		S = 0, P = 0, E = 0, C = 0, I = 0, A = 0, L = 0,
		health = 100,
		radiation = 0,
		stimpack = 0,
		radAway = 0;

	Vec2D *position = new Vec2D(0, 0);

	Outfit *outfit = NULL;
	Weapon *weapon = NULL;

};

#endif