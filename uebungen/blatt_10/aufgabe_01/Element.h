#ifndef ELEMENT_H_
#define ELEMENT_H_

class Element
{
private:
	Element* up, *down, *left, *right;
	int value;
public:
	Element();
	Element(int val);
	virtual ~Element();
	void setUp(Element* val);
	void setDown(Element* val);
	void setLeft(Element* val);
	void setRight(Element* val);
	void setValue(int val);
	Element* getUp();
	Element* getDown();
	Element* getLeft();
	Element* getRight();
	int getVal();
};

#endif /* ELEMENT_H_ */
