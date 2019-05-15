#include "Tree.h"
#include <cstddef>
#include "Knot.h"
#include <iostream>

using namespace std;

Tree::Tree() : root(new Knot())
{
}

Tree::~Tree()
{
	deleteTree(root);
}

void Tree::deleteTree(Knot *root)
{
	if (root->get_left() != nullptr)
		deleteTree(root->get_left());
	if (root->get_right() != nullptr)
		deleteTree(root->get_right());
	delete root;
}

Knot *Tree::get_root()
{
	return root;
}

void Tree::insertValue(int i)
{
	if (root->isUsed() == false)
	{
		Knot *temp = new Knot;
		temp->set_value(i);
		root = temp;
	}
	else
	{
		Knot *temp = new Knot;
		temp->set_value(i);

		Knot *runner = root;
		while (true)
		{
			if (i < runner->get_value())
			{
				if (runner->get_left() == nullptr)
				{
					runner->set_left(temp);
					break;
				}
				else
					runner = runner->get_left();
			}
			else if (i > runner->get_value())
			{
				if (runner->get_right() == nullptr)
				{
					runner->set_right(temp);
					break;
				}
				else
					runner = runner->get_right();
			}
		}
	}
}

bool Tree::containingX(int x)
{
	bool retVal = false;
	for (Knot *runner = root; runner != nullptr;)
	{
		if (runner->get_value() == x)
		{
			retVal = true;
			break;
		}
		else if (runner->get_value() < x)
		{
			runner = runner->get_left();
		}
		else
		{
			runner = runner->get_right();
		}
	}
	return retVal;
}

void Tree::printPre()
{
	printPre(root);
}

void Tree::printIn()
{
	printIn(root);
}

void Tree::printPost()
{
	printPost(root);
}

void Tree::printPre(Knot *root)
{
	if (root == nullptr)
		return;

	cout << "(" << root->get_value() << ",";
	if (root->get_left() != nullptr)
		printPre(root->get_left());
	else
		cout << "n";
	cout << ",";
	if (root->get_right() != nullptr)
		printPre(root->get_right());
	else
		cout << "n";
	cout << ")";
}

void Tree::printIn(Knot *root)
{
	if (root == nullptr)
		return;

	cout << "(";
	if (root->get_left() != nullptr)
		printIn(root->get_left());
	else
		cout << "n";
	cout << "," << root->get_value() << ",";
	if (root->get_right() != nullptr)
		printIn(root->get_right());
	else
		cout << "n";
	cout << ")";
}

void Tree::printPost(Knot *root)
{
	if (root == nullptr)
		return;

	cout << "(";
	if (root->get_left() != nullptr)
		printPost(root->get_left());
	else
		cout << "n";
	cout << ",";
	if (root->get_right() != nullptr)
		printPost(root->get_right());
	else
		cout << "n";
	cout << "," << root->get_value() << ")";
}
