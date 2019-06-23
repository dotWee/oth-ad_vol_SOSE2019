#include <iostream>
#include "Knot.h"
#include "Graph.h"
#include "Matrix.h"

#define amountKnots 6

using namespace std;

int main()
{
	Graph G(amountKnots);
	Matrix *connections = new Matrix(amountKnots, amountKnots);

	for (int i = 0; i < amountKnots; ++i)
	{
		Knot *temp = new Knot(i);
		G.insertKnot(temp);
	}

	int help[amountKnots * amountKnots] = {0, 1, 1, 1, 0, 1,
										   1, 0, 1, 1, 0, 1,
										   1, 1, 0, 1, 1, 1,
										   1, 1, 1, 0, 0, 1,
										   0, 0, 1, 0, 0, 1,
										   1, 1, 1, 1, 1, 0};
	for (int i = 0; i < amountKnots * amountKnots; ++i)
	{
		connections->setValue((int)i / amountKnots, i % amountKnots, help[i]);
	}

	G.setConnections(connections);
	cout << "Knot amount in max Clique " << G.searchMaxClique() << endl;

	return 0;
}
