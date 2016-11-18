#ifndef _VEC2D_H_
#define _VEC2D_H_


class Vec2D
{
public:
	Vec2D();
	Vec2D(double, double);

	~Vec2D();

private:
	struct VecStruct
	{
		double 
			x, 
			y;
	};


};

#endif