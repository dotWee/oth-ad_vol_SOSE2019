#ifndef AVLTREE_H_
#define AVLTREE_H_

#include "Knot.h"

class AVLTree
{
private:

	int Max(int a, int b);
	int GetHeight(Knot* elem);
	void UpdateHeight(Knot* elem);
	void Insert(Knot* &elem,int o);
	void DeleteTree(Knot* root);
	void CheckRotationRight(Knot* &elem);
	void CheckRotationLeft(Knot* &elem);
	void Print(Knot* curr);
	void RotateLeft(Knot* &a);
	void DoubleRotationLeft(Knot* &a);
	void RotateRight(Knot* &a);
	void DoubleRotationRight(Knot* &a);

	void deleteX(Knot* &root, Knot* &prev, int x);
	Knot* goDeepRE(Knot* &root, Knot* &prev);

public:
	AVLTree();
	virtual ~AVLTree();
	void Insert(int o); // Wert einfügen
	void Print();

	void deleteX(int x);
	void checkRotations(Knot* root);

	Knot* findX(Knot* curr, int x);


	Knot* root;
};

#endif /* AVLTREE_H_ */


