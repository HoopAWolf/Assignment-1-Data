#include "Vec2D.h"

Vec2D::Vec2D()
{
	VecStruct vecStruct;

	vecStruct.x = 1;
	vecStruct.y = 1;
}

Vec2D::Vec2D(double x, double y)
{
	VecStruct vecStruct;

	vecStruct.x = x;
	vecStruct.y = y;
}

Vec2D::~Vec2D()
{
	;
}