#include "AVLTree.h"
#include "Knot.h"
#include <iostream>
#include <vector>

using namespace std;

AVLTree::AVLTree() : cnt(0), root(new Knot())
{

}

AVLTree::~AVLTree()
{
	DeleteTree(root);
	root = nullptr;
}

int AVLTree::Max(int a, int b)
{
	if (a<b)
		return b;
	else
		return a;
}

int AVLTree::GetHeight(Knot* elem)
{
	if (elem == nullptr)
		return -1;
	else
		return elem->height;
}

void AVLTree::UpdateHeight(Knot* elem)
{
	elem->height = 1+ Max(GetHeight(elem->left), GetHeight(elem->right));
}

void AVLTree::RotateLeft(Knot* &a)
{
	Knot* b = a->right;
	a->right = b->left;
	b->left = a;
	a = b;
	UpdateHeight(a->left);
	UpdateHeight(a);
}

void AVLTree::RotateRight(Knot* &a)
{
	Knot *b = a->left;
	a->left = b->right;
	b->right = a;
	a = b;
	UpdateHeight(a->right);
	UpdateHeight(a);
}

void AVLTree::DoubleRotationLeft(Knot* &a)
{
	RotateRight(a->right);
	RotateLeft(a);
}

void AVLTree::DoubleRotationRight(Knot* &a)
{
	RotateLeft(a->left);
	RotateRight(a);
}

void AVLTree::CheckRotationRight(Knot* &elem)
{
	if (elem != nullptr)
	{
		if (elem->left != nullptr)
		{
			if (GetHeight(elem->left) - GetHeight(elem->right) == 2)
			{
				if (GetHeight(elem->left->right) > GetHeight(elem->left->left))
				{
					DoubleRotationRight(elem);
				}
				else RotateRight(elem);
			}
			else UpdateHeight(elem);
		}
		else UpdateHeight(elem);
	}
}

void AVLTree::CheckRotationLeft(Knot* &elem)
{
	if (elem != nullptr)
	{
		if (elem->right != nullptr)
		{
			if (GetHeight(elem->right) - GetHeight(elem->left) == 2)
			{
				if (GetHeight(elem->right->left) > GetHeight(elem->right->right))
				{
					DoubleRotationLeft(elem);
				}
				else RotateLeft(elem);
			}
			else UpdateHeight(elem);
		}
		else UpdateHeight(elem);
	}
}

void AVLTree::Insert(Knot* &elem, int o)
{
	if (elem == nullptr)
	{
		elem = new Knot;
		elem->set_height(0);
		elem->set_value(o);
		elem->set_left(nullptr);
		elem->set_right(nullptr);
	}
	else
	{
		if (o <= elem->get_value())
		{
			Insert(elem->left, o);
			CheckRotationRight(elem);
		}
		else
		{
			Insert(elem->right, o);
			CheckRotationLeft(elem);
		}
	}
}



void AVLTree::Insert(int o)
{
	Insert(this->root,o);
}

void AVLTree::DeleteTree(Knot* root)
{
	if (root->get_left() != nullptr)
		DeleteTree(root->get_left());
	if (root->get_right() != nullptr)
		DeleteTree(root->get_right());
	delete root;

}

void AVLTree::Print(Knot* curr)
{
	cout << "(";
	if(curr->get_left() != nullptr)
		Print(curr->get_left());
	else
		cout << "n";
	cout << "," << curr->get_height() << ",";
	if(curr->get_right() != nullptr)
		Print(curr->get_right());
	else
		cout << "n";
	cout << ")";
}

void AVLTree::Print()
{
	Print(this->root);
}


vector<Knot*>* AVLTree::buildTree(/*Knot* root,*/ int deep)
{
	if (deep == 0)
	{
		Knot* newKnot = new Knot();
		vector<Knot*> *newList = new vector<Knot*>();
		UpdateHeight(newKnot);
		newList->push_back(newKnot);
		return newList;
	}

	if (deep == 1)
	{
		Knot* newRoot1 = new Knot(), *newLeav1 = new Knot();
		Knot* newRoot2 = new Knot(), *newLeav2 = new Knot();
		newRoot1->set_left(newLeav1);
		newRoot2->set_right(newLeav2);
		vector<Knot*> *newList = new vector<Knot*>();
		newList->push_back(newRoot1);
		newList->push_back(newRoot2);

		UpdateHeight(newLeav1);
		UpdateHeight(newLeav2);
		UpdateHeight(newRoot1);
		UpdateHeight(newRoot2);

		return newList;
	}

	vector<Knot*> *left = new vector<Knot*>(), *right = new vector<Knot*>();
	left = buildTree(deep-1);												//alle teilbäume der höhe deep-1
	right = buildTree(deep-2);												//alle teilbäume der höhe deep-2

	vector<Knot*> *retVal = new vector<Knot*>();

	//alle permutationen bauen
	for (unsigned int i=0; i<left->size(); ++i)		//links an links hängen
	{
		for (unsigned int j=0; j<right->size(); ++j)
		{
			Knot* newRoot = new Knot();
			newRoot->left = (*left)[i];
			newRoot->right = (*right)[j];
			retVal->push_back(newRoot);
			UpdateHeight(newRoot);
		}
	}


	for (unsigned int i=0; i<left->size(); ++i)		//links an rechts hängen
	{
		for (unsigned int j=0; j<right->size(); ++j)
		{
			Knot* newRoot = new Knot();
			newRoot->right = (*left)[i];
			newRoot->left = (*right)[j];
			retVal->push_back(newRoot);
			UpdateHeight(newRoot);
		}
	}

	return retVal;
}
