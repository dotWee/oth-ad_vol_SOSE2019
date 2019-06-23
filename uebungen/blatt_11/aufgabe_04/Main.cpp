#include <iostream>
#include "Knot.h"
#include "Graph.h"
#include "Matrix.h"

#define amountKnots 9

using namespace std;

int main()
{

	Graph G(amountKnots);
	Matrix *connections = new Matrix(amountKnots, amountKnots);

	for (int i = 0; i < 9; ++i) //init knots in list
	{
		Knot *temp = new Knot(i);
		G.insertKnot(temp);
	}

	int help[amountKnots * amountKnots] = {
		0,
		1,
		1,
		0,
		0,
		0,
		1,
		0,
		0,
		0,
		0,
		0,
		1,
		0,
		0,
		0,
		0,
		0,
		1,
		0,
		0,
		1,
		1,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		1,
		0,
		0,
		1,
		0,
		0,
		0,
		0,
		1,
		0,
		0,
		1,
		0,
		0,
		1,
		1,
		1,
		0,
		0,
		1,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		1,
		0,
		0,
		0,
		0,
		1,
		0,
		0,
		0,
		0,
		1,
		0,
		0,
		0,
		0,
		0,
		1,
		0,
		0,
		0,
	};
	for (int i = 0; i < amountKnots * amountKnots; ++i)
	{
		connections->setValue((int)i / amountKnots, i % amountKnots, help[i]);
	}

	G.setConnections(connections);

	G.deapSearch(0);
	G.rangeSearch(0);

	return 0;
}
