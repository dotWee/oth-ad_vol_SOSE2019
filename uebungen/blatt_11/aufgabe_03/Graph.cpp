#include "Graph.h"
#include <list>
#include <vector>
using namespace std;

Graph::Graph(int amaountKnots) : connections(nullptr)
{
}

Graph::~Graph()
{
}

void Graph::insertKnot(Knot* knot)
{
	knots.push_back(knot);
}

void Graph::setConnections(Matrix* values)
{
	connections = values;
}

void Graph::deapSearch(Knot* curr)
{
	if (curr->get_visited() == true)
		return;
	else
		curr->set_visited(true);
	for(int i=0; i<(int)knots.size(); ++i)
	{
		if (connections->getValue(curr->get_name(), i) != 0)
		{
			deapSearch(knots[i]);
		}
	}
	cout << curr->get_name() << " " ;
}

void Graph::deapSearch(int knot)
{
	cout << "Deep-Search" << endl;
	if (knot >= (int)knots.size())
	{
		cout << "Biggest knot is " << knots.size()-1 << endl;
		return;
	}
	deapSearch(knots[knot]);
	cout << endl;
	cleanUp();
}

void Graph::cleanUp()
{
	for (Knot* a : knots)
	{
		a->set_visited(false);
	}
}

void Graph::rangeSearch(int knot)
{
	if (knot >= (int)knots.size())
	{
		cout << "Biggest knot is " << knots.size()-1 << endl;
		return;
	}

	list<Knot*> toDo;
	toDo.push_back(knots[knot]);

	cout << "Range search" << endl;
	while(toDo.empty() == false)
	{
		Knot* temp = toDo.front();
		toDo.pop_front();
		cout << temp->get_name() << " ";
		temp->set_visited(true);

		for(int i=0; i<(int)knots.size(); ++i)
		{
			if (connections->getValue(temp->get_name(), i) != 0)
			{
				if (knots[i]->get_visited() == false)
				{
					toDo.push_back(knots[i]);
					knots[i]->set_visited(true);
				}

			}
		}
	}
	cleanUp();
	cout << endl;
}

bool Graph::checkClique(std::vector<Knot*>* knotList)
{
	//schaut ob bei einer übergebenen liste mit Knöten alle Knöten zu dem nKnot eine verbindung haben
	bool retVal = true;

	for(Knot* k : *knotList)
	{
		for(Knot* m : *knotList)
		{
			if(k->get_name() == m->get_name())
				continue;
			if(connections->getValue(k->get_name(), m->get_name()) == 0) //verbindung ist nicht da
			{
				return false;
			}
		}
	}
	return retVal;
}

int Graph::searchMaxClique()
{
	int retVal = 0;
	unsigned int mask = 0;

	int cnt = 1;
	for (int i=0; i<(int)knots.size(); ++i)
		cnt = cnt *2;

	for (int i=0; i<cnt; ++i)
	{
		vector<Knot*>* currClique = new vector<Knot*>();

		for (int j=0; j<(int)knots.size(); ++j)
		{
			if( (mask & (1<<j)) != 0)
				currClique->push_back(knots[j]);
		}

		if (checkClique(currClique))
		{
			if( (int)currClique->size() > retVal)
				retVal = currClique->size();
		}
		incMask(mask);
	}
	return retVal;
}

void Graph::incMask(unsigned int& m) //dient dazu, dass man alle permutationen druch probiert
{
	int runner = 0;
	while(true)
	{
		if( (m & 1<<runner) == 0)
		{
			m = m | (1<<runner);
			break;
		}
		else
		{
			m = m & ~(1<<runner);
			++runner;
		}
	}
}


