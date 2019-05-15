#include "Knot.h"
#include <cstddef>

Knot::Knot() : left(nullptr), right(nullptr), value(0), used(false)
{
}

Knot::~Knot()
{
}

bool Knot::isUsed()
{
	return used;
}

Knot *Knot::get_left()
{
	return left;
}

Knot *Knot::get_right()
{
	return right;
}

int Knot::get_value()
{
	return value;
}

void Knot::set_right(Knot *knot)
{
	this->right = knot;
}

void Knot::set_left(Knot *knot)
{
	this->left = knot;
}

void Knot::set_value(int val)
{
	value = val;
	used = true;
}
