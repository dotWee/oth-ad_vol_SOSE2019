#include "AVLTree.h"
#include "Knot.h"
#include <iostream>

using namespace std;

AVLTree::AVLTree() : root(nullptr)
{
}

AVLTree::~AVLTree()
{
	DeleteTree(root);
	root = nullptr;
}

int AVLTree::Max(int a, int b)
{
	if (a < b)
		return b;
	else
		return a;
}

int AVLTree::GetHeight(Knot *elem)
{
	if (elem == nullptr)
		return -1;
	else
		return elem->height;
}

void AVLTree::UpdateHeight(Knot *elem)
{
	elem->height = 1 + Max(GetHeight(elem->left), GetHeight(elem->right));
}

void AVLTree::RotateLeft(Knot *&a)
{
	Knot *b = a->right;
	a->right = b->left;
	b->left = a;
	a = b;
	UpdateHeight(a->left);
	UpdateHeight(a);
}

void AVLTree::RotateRight(Knot *&a)
{
	Knot *b = a->left;
	a->left = b->right;
	b->right = a;
	a = b;
	UpdateHeight(a->right);
	UpdateHeight(a);
}

void AVLTree::DoubleRotationLeft(Knot *&a)
{
	RotateRight(a->right);
	RotateLeft(a);
}

void AVLTree::DoubleRotationRight(Knot *&a)
{
	RotateLeft(a->left);
	RotateRight(a);
}

void AVLTree::CheckRotationRight(Knot *&elem)
{
	if (elem != nullptr)
	{
		if (elem->left != nullptr)
		{
			//if (GetHeight(elem->left) - GetHeight(elem->right) == 2)
			int diff = GetHeight(elem->left) - GetHeight(elem->right);
			diff = diff < 0 ? diff * (-1) : diff;
			if (diff > 1)
			{
				if (GetHeight(elem->left->right) > GetHeight(elem->left->left))
				{
					DoubleRotationRight(elem);
				}
				else
					RotateRight(elem);
			}
			else
				UpdateHeight(elem);
		}
		else
			UpdateHeight(elem);
	}
}

void AVLTree::CheckRotationLeft(Knot *&elem)
{
	if (elem != nullptr)
	{
		if (elem->right != nullptr)
		{
			//if (GetHeight(elem->right) - GetHeight(elem->left) == 2)
			int diff = GetHeight(elem->right) - GetHeight(elem->left);
			diff = diff < 0 ? diff * (-1) : diff;
			if (diff > 1)
			{
				if (GetHeight(elem->right->left) > GetHeight(elem->right->right))
				{
					DoubleRotationLeft(elem);
				}
				else
					RotateLeft(elem);
			}
			else
				UpdateHeight(elem);
		}
		else
			UpdateHeight(elem);
	}
}

void AVLTree::Insert(Knot *&elem, int o)
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
	Insert(this->root, o);
}

void AVLTree::DeleteTree(Knot *root)
{
	if (root->left != nullptr)
		DeleteTree(root->left);
	if (root->right != nullptr)
		DeleteTree(root->right);
	delete root;
}

void AVLTree::Print(Knot *curr)
{
	cout << "(";
	if (curr->left != nullptr)
		Print(curr->left);
	else
		cout << "n";
	cout << "," << curr->get_value() << "[" << curr->height << "]"
		 << ",";
	if (curr->right != nullptr)
		Print(curr->right);
	else
		cout << "n";
	cout << ")";
}

void AVLTree::Print()
{
	Print(this->root);
}

void AVLTree::deleteX(int x)
{
	Knot *nullKnot = nullptr;
	deleteX(root, nullKnot, x);
}

void AVLTree::deleteX(Knot *&root, Knot *&prev, int x)
{
	if (root->get_value() == x)
	{
		if (root->left == nullptr && root->right == nullptr) //blatt
		{
			if (this->root == root)
			{
				this->root = nullptr;
			}
			else
			{
				if (root->get_value() < prev->get_value())
					prev->left = nullptr;
				else
					prev->right = nullptr;
			}
			delete root;
		}
		else
		{
			if (root->left == nullptr && root->right != nullptr) //nur rechts nachfolger
			{
				if (this->root == root)
				{
					this->root = root->right;
				}
				else
				{
					if (root->get_value() < prev->get_value())
						prev->left = root->right;
					else
						prev->set_right(root->right);
				}
				delete root;
			}
			else if (root->left != nullptr && root->right == nullptr) //nur links nachfolger
			{
				if (this->root == root)
				{
					this->root = root->left;
				}
				else
				{
					if (root->get_value() < prev->get_value())
						prev->left = root->left;
					else
						prev->set_right(root->left);
				}
				delete root;
			}
			else // rechts und links nachfolger
			{
				Knot *temp = root;
				root = goDeepRE(temp->left, root);
				cout << "tempVal2 " << root->get_value() << endl;

				root->left = (temp->left == root) ? root->left : temp->left; //hier gibt es problem wenn der größte gleich der erste im linken baum ist, deswegn spezial betrachtung
				root->right = temp->right;									 //da max aus linken baum such ist des egal

				if (root != nullptr)
					UpdateHeight(root);
				if (this->root == temp)
				{
					this->root = root;
				}
				else
				{
					if (temp->get_value() < prev->get_value()) //sind vorher nach links
					{
						prev->left = root;
						CheckRotationLeft(root);
					}
					else //sind vorher nach rechts
					{
						prev->right = root;
						CheckRotationRight(root);
					}
				}
				delete temp;
			}
		}
	}
	else //wert noch nicht gefunden weiter gehen
	{
		if (x < root->get_value() && root->left != nullptr)
		{
			deleteX(root->left, root, x); //links weiter
			UpdateHeight(root);
			CheckRotationLeft(root);
		}
		else if (root->get_value() < x && root->right != nullptr)
		{
			deleteX(root->right, root, x); //rechts weiter
			UpdateHeight(root);
			CheckRotationRight(root);
		}
	}
}

Knot *AVLTree::goDeepRE(Knot *&root, Knot *&prev) //nehme vom Knoten ausgesehen den rechtersten größten im linkersten Teilbaum
{
	if (root->left == nullptr && root->right == nullptr) // blatt
	{
		Knot *retVal = root;
		if (root == prev->left)
			prev->set_left(nullptr);
		else if (prev->right == root)
			prev->set_right(nullptr);
		return retVal;
	}
	else if (root->left != nullptr && root->right == nullptr) //links geht es weiter, rechts aber nicht
	{
		Knot *retVal = root;
		if (prev->right == root)
			prev->set_right(root->left);
		else if (prev->left == root)
			prev->set_left(root->left);
		return retVal;
	}

	Knot *temp = goDeepRE(root->right, root); //speicher mit den untersten zwischen
	UpdateHeight(root);

	if (root->get_value() < prev->get_value())
		CheckRotationLeft(root);
	else if (prev->get_value() < root->get_value())
		CheckRotationRight(root);

	return temp;
}

Knot *AVLTree::findX(Knot *curr, int x)
{
	if (curr->get_value() == x)
		return curr;

	return findX(x < curr->get_value() ? curr->left : curr->right, x);
}
