//============================================================================
// Name        : Aufgabe2.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "AVLTree.h"
#include <vector>

using namespace std;

int main()
{
	AVLTree tree;

	int hight = 5;
	vector<Knot *> *temp = tree.buildTree(hight);

	cout << "Es gibt " << temp->size() << " viele Bäume der Höhe " << hight << endl;

	for (int i = 0; i < (int)temp->size(); ++i)
	{
		cout << "Tree " << i << endl;
		tree.Print((*temp)[i]);
		cout << endl;
	}

	return 0;
}
