#include "GameObject.h"

int GameObject::count = 0;

GameObject::~GameObject()
{
	this->count--;
}

string GameObject::getName()
{
	return kName;
}

int GameObject::getCount()
{
	return count;
}