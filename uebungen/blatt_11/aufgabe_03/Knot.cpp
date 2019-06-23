#include "Knot.h"

Knot::Knot(int name) : visited(false), name(name)
{
}

Knot::~Knot()
{
}

bool Knot::get_visited()
{
	return visited;
}

void Knot::set_visited(bool newState)
{
	visited = newState;
}

int Knot::get_name()
{
	return name;
}
