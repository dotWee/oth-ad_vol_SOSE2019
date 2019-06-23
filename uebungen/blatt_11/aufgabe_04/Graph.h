#ifndef GRAPH_H_
#define GRAPH_H_

#include <list>
#include <vector>
#include "Knot.h"
#include "Matrix.h"

using namespace std;

class Graph
{
  private:
	vector<Knot *> knots;
	Matrix *connections;
	void deapSearch(Knot *curr);
	void cleanUp();
	bool checkClique(std::vector<Knot *> *knotList);
	void incMask(unsigned int &m);

  public:
	Graph(int amaountKnots);
	virtual ~Graph();
	void insertKnot(Knot *knot);
	void setConnections(Matrix *values);
	void deapSearch(int knot);
	void rangeSearch(int knot);
	int searchMaxClique();
};

#endif /* GRAPH_H_ */
