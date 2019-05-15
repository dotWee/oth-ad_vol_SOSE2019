#ifndef REBUILDTREE_H_
#define REBUILDTREE_H_

#include "Tree.h"
#include "Knot.h"
#include <string>

class RebuildTree
{
private:
	void preANDin(Knot* root, int* pre, int* in, int inPre, int startIn, int endIn);
	void inANDpost(Knot* root, int* post, int* in, int inPost, int startIn, int endIn);

	void preANDin(Tree* tree, int* pre, int* in, int inPre, int startIn, int endIn);
	void inANDpost(Tree* tree, int* post, int* in, int inPost, int startIn, int endIn);
	void onlyPre(Knot* knot, std::string str, int start, int stop);
	void findBrackets(std::string str, int start, int stop, int& open1, int& close1, int& open2, int& close2);
	int getNumber(std::string str, int start, int stop);
	int getNumber(std::string str, int start);
public:
	RebuildTree();
	virtual ~RebuildTree();
	void preANDin(Knot* root, int* pre, int* in, int length);
	void inANDpost(Knot* root, int* in, int* post, int length);
	void onlyPre(Tree* tree, int* pre, int length);

	void preANDin(Tree* tree, int* pre, int* in, int length);
	void inANDpost(Tree* tree, int* in, int* post, int length);
	void onlyPre(Knot* root, std::string str, int length);
};

#endif /* REBUILDTREE_H_ */
