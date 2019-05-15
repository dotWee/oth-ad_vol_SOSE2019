#include "Knot.h"
#include <cstddef>

Knot::Knot() : left(nullptr), right(nullptr), value(0), height(-1), used(false)
{
	// TODO Auto-generated constructor stub
}

Knot::~Knot() {
	// TODO Auto-generated destructor stub
}

int Knot::get_height()
{
	return this->height;
}

void Knot::set_height(int height)
{
	this->height = height;
}

bool Knot::isUsed()
{
	return used;
}

Knot* Knot::get_left()
{
	return left;
}

Knot* Knot::get_right()
{
	return right;
}

int Knot::get_value()
{
	return value;
}

void Knot::set_right(Knot* knot)
{
	this->right = knot;
}

void Knot::set_left(Knot* knot)
{
	this->left = knot;
}

void Knot::set_value(int val)
{
	value = val;
	used =  true;
}

