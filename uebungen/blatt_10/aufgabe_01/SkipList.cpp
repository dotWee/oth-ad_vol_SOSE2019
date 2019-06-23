#include "SkipList.h"
#include "Element.h"
#include <limits>
#include <random>
#include <iostream>

using namespace std;

#define negInf std::numeric_limits<int>::min()
#define posInf std::numeric_limits<int>::max()

SkipList::SkipList() : top(new Element()), retreat(false)
{
}

SkipList::~SkipList()
{
}

void SkipList::print()
{
	cout << "Skip-Liste" << endl;
	Element *temp = top;
	while (temp->getDown() != nullptr)
	{
		temp = temp->getDown();
	}

	print(temp);
	cout << endl
		 << endl;
}

void SkipList::print(Element *curr)
{
	int i = 0;
	Element *temp = curr;
	while (temp->getUp() != nullptr)
	{
		++i;
		temp = temp->getUp();
	}
	if (curr->getVal() == negInf)
		cout << "|(" << i << ") ";
	else
		cout << curr->getVal() << "(" << i << ") ";

	if (curr->getRight() != nullptr)
		print(curr->getRight());
}

void SkipList::insertX(int x)
{
	insertX(top, x);
}

Element *SkipList::buildTower(int x)
{
	std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_int_distribution<int> uni(negInf, posInf);

	auto random_integer = uni(rng);

	Element *newEle = new Element(x);
	Element *help = newEle;

	while (random_integer % 2 == 0)
	{
		random_integer = uni(rng);

		Element *newEle2 = new Element(x);
		help->setUp(newEle2);
		newEle2->setDown(help);
		help = newEle2;
	}
	return newEle;
}

Element *SkipList::whereToGo(Element *curr, int x)
{
	Element *retVal = nullptr;

	if (curr->getVal() < x)
	{
		if (curr->getRight() != nullptr && curr->getRight()->getVal() <= x)
		{
			retVal = curr->getRight();
		}
		else if (curr->getDown() != nullptr)
		{
			retVal = curr->getDown();
		}
	}
	return retVal;
}

void SkipList::insertX(Element *curr, int x)
{
	if (curr->getVal() == x)
		return;

	Element *temp = whereToGo(curr, x);
	if (temp != nullptr)
	{
		insertX(temp, x);
		if (curr->getDown() != nullptr && curr->getDown() == temp)
		{
			Element *runner = curr->getDown();

			while (runner->getRight() != nullptr)
			{
				runner = runner->getRight();
				if (runner->getVal() >= x)
					break;
			}

			if (runner->getVal() == x)
			{
				if (runner->getUp() != nullptr)
				{
					Element *currTopTower = runner->getUp();

					currTopTower->setRight(curr->getRight());
					currTopTower->setLeft(curr);
					if (curr->getRight() != nullptr)
						curr->getRight()->setLeft(currTopTower);
					curr->setRight(currTopTower);
				}
			}
		}
	}
	else
	{
		Element *newEle = buildTower(x);
		newEle->setLeft(curr);
		newEle->setRight(curr->getRight());
		if (curr->getRight() != nullptr)
			curr->getRight()->setLeft(newEle);
		curr->setRight(newEle);
	}

	if (curr == top)
	{
		if (curr->getRight() != nullptr)
		{
			Element *runnerTower = curr;

			bool run = true;
			while (run)
			{
				if (runnerTower->getVal() == x)
				{
					run = false;
					break;
				}
				if (runnerTower->getVal() > x)
				{
					run = false;
					break;
				}
				if (runnerTower->getRight() == nullptr)
				{
					run = false;
					break;
				}
				runnerTower = runnerTower->getRight();
			}

			if (runnerTower->getVal() > x)
			{
				if (runnerTower->getLeft() != nullptr)
					runnerTower = runnerTower->getLeft();
			}

			if (runnerTower->getVal() == x)
			{

				while (runnerTower->getUp() != nullptr)
				{
					Element *newTop = new Element(negInf);
					newTop->setRight(runnerTower->getUp());
					runnerTower->getUp()->setLeft(newTop);
					top->setUp(newTop);
					newTop->setDown(top);
					top = newTop;
					runnerTower = runnerTower->getUp();
				}
			}
		}
	}
	return;
}

bool SkipList::searchX(int x)
{
	return searchX(top, x);
}

bool SkipList::searchX(Element *curr, int x)
{
	bool retVal = false;

	Element *temp = whereToGo(curr, x);
	if (temp != nullptr)
	{
		if (temp->getVal() == x)
			retVal = true;
		else
			retVal = searchX(temp, x);
	}

	return retVal;
}

void SkipList::deleteX(int x)
{
	cout << "Will delete " << x << endl;
	deleteX(top, x);
}

void SkipList::deleteX(Element *curr, int x)
{
	while (curr->getDown() != nullptr)
	{
		curr = curr->getDown();
	}

	while (curr->getRight() != nullptr && curr->getVal() != x)
	{
		curr = curr->getRight();
	}

	if (curr->getVal() == x)
	{
		deleteTower(curr);
	}
}

void SkipList::deleteTower(Element *curr)
{
	while (curr->getDown() != nullptr)
	{
		curr = curr->getDown();
	}

	while (curr != nullptr)
	{
		if (curr->getLeft() != nullptr)
			curr->getLeft()->setRight(curr->getRight());
		if (curr->getRight() != nullptr)
			curr->getRight()->setLeft(curr->getLeft());
		Element *victim = curr;
		curr = curr->getUp();
		delete victim;
	}
}