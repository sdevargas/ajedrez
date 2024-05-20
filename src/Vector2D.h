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
	Vector2D operator + (Vector2D v);
	
};

inline Vector2D Vector2D:: operator - (Vector2D v) {
	Vector2D res;
	res.x = x - v.x;
	res.y = y - v.y;
	return res;

}
inline Vector2D Vector2D:: operator + (Vector2D v) {
	Vector2D res;
	res.x = x + v.x;
	res.y = y + v.y;
	return res;

}