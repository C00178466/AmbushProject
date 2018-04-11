#pragma once

struct Point2D
{
	float x;
	float y;
	
	Point2D() {};

	Point2D(float X, float Y)
	{
		x = X;
		y = Y;
	}

	float Length()
	{
		return sqrt(x * x + y * y);
	}
};

//static Point2D Normalize(int value)
//{
//	Point2D temp;
//	float length = Length();
//}
