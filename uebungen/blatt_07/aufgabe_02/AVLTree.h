/*
 * AVLTree.h
 *
 *  Created on: 01.05.2015
 *      Author: franz
 */

#ifndef AVLTREE_H_
#define AVLTREE_H_

#include "Knot.h"
#include <vector>

class AVLTree
{
private:
	int cnt;

	int Max(int a, int b);
	int GetHeight(Knot* elem);
	void UpdateHeight(Knot* elem);
	void Insert(Knot* &elem,int o);
	void DeleteTree(Knot* root);
	void CheckRotationRight(Knot* &elem);
	void CheckRotationLeft(Knot* &elem);

	void RotateLeft(Knot* &a);
	void DoubleRotationLeft(Knot* &a);
	void RotateRight(Knot* &a);
	void DoubleRotationRight(Knot* &a);

	void permutate(Knot* root);



public:
	Knot* root;

	AVLTree();
	virtual ~AVLTree();
	void Insert(int o); // Wert einfügen
	void Print();
	std::vector<Knot*>* buildTree(/*Knot* root,*/ int deep);
	void Print(Knot* curr);


};

#endif /* AVLTREE_H_ */


