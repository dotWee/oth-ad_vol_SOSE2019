#ifndef TREE_H_
#define TREE_H_

#include "Knot.h"

class Tree
{
  private:
	Knot *root;
	void printPre(Knot *root);
	void printIn(Knot *root);
	void printPost(Knot *root);
	void deleteTree(Knot *root);

  public:
	Tree();
	virtual ~Tree();
	Knot *get_root();
	void insertValue(int i);
	bool containingX(int x);
	void printPre();
	void printIn();
	void printPost();
};

#endif /* TREE_H_ */
