#include <iostream>
#include "AVLTree.h"

using namespace std;

int main()
{

	AVLTree tree;
	tree.Insert(5);
	//	tree.Print();
	//	cout << endl << endl;

	tree.Insert(6);
	//	tree.Print();
	//	cout << endl << endl;

	tree.Insert(9);
	//	tree.Print();
	//	cout << endl << endl;

	tree.Insert(12);
	//	tree.Print();
	//	cout << endl << endl;

	tree.Insert(13);
	//	tree.Print();
	//	cout << endl << endl;

	tree.Insert(3);
	//	tree.Print();
	//	cout << endl << endl;

	tree.Insert(8);
	//	tree.Print();
	//	cout << endl << endl;

	tree.Insert(10);
	//	tree.Print();
	//	cout << endl << endl;

	tree.Insert(11);
	//	tree.Print();
	//	cout << endl << endl;

	tree.Insert(16);
	//	tree.Print();
	//	cout << endl << endl;

	tree.Insert(15);
	//	tree.Print();
	//	cout << endl << endl;

	tree.Insert(14);
	//	tree.Print();
	//	cout << endl << endl;

	tree.Insert(6);
	//	tree.Print();
	//	cout << endl << endl;

	tree.Insert(4);
	//	tree.Print();
	//	cout << endl << endl;

	tree.Insert(2);
	//	tree.Print();
	//	cout << endl << endl;

	tree.Insert(1);
	tree.Print();
	cout << endl
		 << endl;

	int i;

	/*	tree.deleteX(12);
	cout << "12 raus" << endl;
	tree.deleteX(8);
	cout << "8 raus" << endl;
	tree.Print();

	cout << "12 raus" << endl;
tree.deleteX(12);
cout << "13 raus" << endl;
tree.deleteX(13);
*/
	while (true)
	{
		cout << endl
			 << "waiting for user input" << endl;
		cin >> i;
		tree.deleteX(i);
		cout << i << " raus" << endl;
		tree.Print();
	}

	cout << "done";
	return 0;
}
