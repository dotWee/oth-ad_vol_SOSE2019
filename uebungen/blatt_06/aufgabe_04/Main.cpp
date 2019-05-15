#include <iostream>
#include "Tree.h"
#include "RebuildTree.h"

using namespace std;

int main()
{
	int length = 9;

	Tree tree;
	tree.insertValue(5);
	tree.insertValue(8);
	tree.insertValue(2);
	tree.insertValue(6);
	tree.insertValue(4);
	tree.insertValue(3);
	tree.insertValue(7);
	tree.insertValue(1);
	tree.insertValue(9);

	int pre[] = {5, 2, 1, 4, 3, 8, 6, 7, 9};
	int in[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int post[] = {1, 3, 4, 2, 7, 6, 9, 8, 5};

	string onlyPre = "(5,(2,(1,n,n),(4,(3,n,n),n)),(8,(6,n,(7,n,n)),(9,n,n)))";

	Tree *newTree = new Tree();
	Tree *newTree2 = new Tree();
	Tree *newTree3 = new Tree();
	RebuildTree bob;

	bob.preANDin(newTree->get_root(), pre, in, length);
	cout << "Restored Tree wit pre and in" << endl;
	newTree->printIn();

	cout << endl
		 << endl;

	bob.inANDpost(newTree2->get_root(), in, post, length);
	cout << "Restored Tree wit pre and in" << endl;
	newTree2->printIn();
	cout << endl
		 << endl;

	Tree *tree2 = new Tree();
	bob.onlyPre(tree2, pre, length);
	cout << "Restored Tree with only Pre" << endl;

	tree2->printIn();
	cout << endl;

	return 0;
}
