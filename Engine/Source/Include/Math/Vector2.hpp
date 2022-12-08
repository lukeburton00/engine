#pragma once
#include <stdio.h>

class Vector2
{
public:
	float x;
	float y;
	
	// Parametrized constructor
	Vector2(float x, float y)
	{
		this->x = x;
		this->y = y;
	}
	
	// Default constructor
	Vector2();
	
	// Operator overload for 2D vector ADDITION
	Vector2 operator+(const Vector2 &inputVector2)
	{
		Vector2 result;
		
		result.x = this->x + inputVector2.x;
		result.y = this->y + inputVector2.y;
		
		return result;
	}
	
	// Operator overload for 2D vector SUBTRACTION
	Vector2 operator-(const Vector2 &inputVector2)
	{
		Vector2 result;
		
		result.x = this->x - inputVector2.x;
		result.y = this->y - inputVector2.y;
		
		return result;
	}
		
		
};
