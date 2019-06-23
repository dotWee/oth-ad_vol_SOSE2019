#ifndef SKIPLIST_H_
#define SKIPLIST_H_

#include "Element.h"

class SkipList
{
private:
	Element* top;
	bool retreat;

	void insertX(Element* curr, int x);
	Element* whereToGo(Element* curr, int x);
	Element* buildTower(int x);
	void print(Element* curr);
	bool searchX(Element* curr, int x);
	void deleteX(Element* curr, int x);
	void deleteTower(Element* curr);

public:
	SkipList();
	virtual ~SkipList();
	void print();
	void insertX(int x);
	void deleteX(int x);
	bool searchX(int x);
};

#endif /* SKIPLIST_H_ */