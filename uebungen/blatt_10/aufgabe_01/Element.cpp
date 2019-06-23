#include "Element.h"
#include <limits>

Element::Element(int val) : up(nullptr), down(nullptr), left(nullptr), right(nullptr), value(val)
{
}

Element::Element() : up(nullptr), down(nullptr), left(nullptr), right(nullptr), value(std::numeric_limits<int>::min())
{
}

Element::~Element()
{
}

void Element::setUp(Element *val)
{
	up = val;
}

void Element::setDown(Element *val)
{
	down = val;
}

void Element::setLeft(Element *val)
{
	left = val;
}

void Element::setRight(Element *val)
{
	right = val;
}

void Element::setValue(int val)
{
	value = val;
}

Element *Element::getUp()
{
	return up;
}

Element *Element::getDown()
{
	return down;
}

Element *Element::getLeft()
{
	return left;
}

Element *Element::getRight()
{
	return right;
}

int Element::getVal()
{
	return value;
}
