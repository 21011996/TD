#pragma once
#include <math.h>

namespace td{

	struct MyMath
	{

	};

	struct MyVector
	{
		MyVector(float x, float y) : m_x(x), m_y(y), m_length(sqrt(x*x+y*y)) {};
		float getX();
		float getY();
		float getLength();
		MyVector getNormilized();


	private :
		float m_x, m_y;
		float m_length;
	};

}