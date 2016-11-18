#ifndef _GAME_OBJECT_H_
#define _GAME_OBJECT_H_

#include <String>

using std::string;


class GameObject
{
public:
	explicit GameObject(const string &name) 
		: kName(name)
	{
		count++;
	};

	virtual ~GameObject();

	virtual string getName(void);
	static int getCount();

private:
	const string kName;
	static int count;
};

#endif