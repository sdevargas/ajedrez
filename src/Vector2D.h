#pragma once

class Vector2D {
public:	
	int x, y;

	Vector2D() : x(0), y(0) {} //constructor predeterminado

	Vector2D(int x, int y) {
		this->x = x;
		this->y = y;
	}
	Vector2D operator - (Vector2D v);
};