#include "RebuildTree.h"
#include <iostream>
#include "Knot.h"
#include <string>

using namespace std;

RebuildTree::RebuildTree()
{
}

RebuildTree::~RebuildTree()
{
}


void RebuildTree::preANDin(Knot* root, int* pre, int* in, int length)
{
	preANDin(root, pre, in, 0, 0, length-1);
}

void RebuildTree::preANDin(Knot* root, int* pre, int* in, int inPre, int startIn, int endIn)
{
	if(startIn > endIn)
	{
		return;
	}

	if (root->isUsed() == false)
	{
		root->set_value(pre[inPre]);
		int posIn;
			for(posIn=startIn; posIn<=endIn; ++posIn)
			{
				if(in[posIn] == pre[inPre])
					break;
			}
			posIn = posIn - startIn; 

			Knot* left = new Knot(), *right = new Knot();
			preANDin(left, pre, in, inPre+1,       startIn, startIn+posIn-1);
			preANDin(right, pre, in, inPre+1+posIn, startIn+posIn+1, endIn);

			if (left->isUsed() == false)
			{
				delete left;
				root->set_left(nullptr);
			}
			else
			{
				root->set_left(left);
			}

			if (right->isUsed() == false)
			{
				delete right;
				root->set_right(nullptr);
			}
			else
			{
				root->set_right(right);
			}
	}
}

void RebuildTree::inANDpost(Knot* root, int* in, int* post, int length)
{
	inANDpost(root, post, in, length-1, 0, length-1);
}

void RebuildTree::inANDpost(Knot* root, int* post, int* in, int inPost, int startIn, int endIn)
{
	if(startIn > endIn)
	{
		return;
	}

	if (root->isUsed() == false)
	{
		root->set_value(post[inPost]);
		int posIn;
		for(posIn=endIn; posIn>=startIn; --posIn)
		{
			if(in[posIn] == post[inPost])
			break;
		}
		posIn = endIn - posIn;

		Knot *left = new Knot(), *right = new Knot();
		inANDpost(left, post, in, inPost-posIn-1, startIn, endIn-posIn-1);
		inANDpost(right, post, in, inPost-1, endIn-posIn+1 , endIn);

		if (left->isUsed() == false)
		{
			delete left;
			root->set_left(nullptr);
		}
		else
		{
			root->set_left(left);
		}

		if (right->isUsed() == false)
		{
			delete right;
			root->set_right(nullptr);
		}
		else
		{
			root->set_right(right);
		}
	}
}

void RebuildTree::onlyPre(Tree* tree, int* pre, int length)
{
	for(int i=0; i<length; ++i)
	{
		tree->insertValue(pre[i]);
	}
}

void RebuildTree::preANDin(Tree* tree, int* pre, int* in, int length)
{
	preANDin(tree, pre, in, 0, 0, length-1);
}

void RebuildTree::preANDin(Tree* tree, int* pre, int* in, int inPre, int startIn, int endIn)
{
	if(startIn > endIn)
	{
		return;
	}

	tree->insertValue(pre[inPre]);
	int posIn;
	for(posIn=startIn; posIn<=endIn; ++posIn)
	{
		if(in[posIn] == pre[inPre])
			break;
	}
	posIn = posIn - startIn;
	preANDin(tree, pre, in, inPre+1,       startIn, startIn+posIn-1);
	preANDin(tree, pre, in, inPre+1+posIn, startIn+posIn+1, endIn);
}

void RebuildTree::inANDpost(Tree* tree, int* in, int* post, int length)
{
	inANDpost(tree, post, in, length-1, 0, length-1);
}

void RebuildTree::inANDpost(Tree* tree, int* post, int* in, int inPost, int startIn, int endIn)
{
	if(startIn > endIn)
	{
		return;
	}

	tree->insertValue(post[inPost]);
	int posIn;
	for(posIn=endIn; posIn>=startIn; --posIn) 
	{
		if(in[posIn] == post[inPost])
			break;
	}
	posIn = endIn - posIn; 

	inANDpost(tree, post, in, inPost-posIn-1, startIn         , endIn-posIn-1);	
	inANDpost(tree, post, in, inPost-1    , endIn-posIn+1 , endIn);
}

void RebuildTree::onlyPre(Knot* knot, std::string str, int length)
{
	onlyPre(knot, str, 0, length-1);
}

void RebuildTree::onlyPre(Knot* knot, string str, int start, int stop)
{
	if((start > stop) || (start == -1 && stop == -1))
		return;

	if(knot->isUsed() == false)
	{

		int open1, open2, close1, close2;
		findBrackets(str, start, stop, open1, close1, open2, close2);
		if (str[start+1] == 'n')
		{
		}
		else
		{
			knot->set_value(getNumber(str, start+1));
			onlyPre(knot, str, open1, close1);
			onlyPre(knot, str, open2, close2);
		}
	}
	else
	{
		int open1, open2, close1, close2;
		findBrackets(str, start, stop, open1, close1, open2, close2);
		if (str[start+1] == 'n')
		{
		}
		else
		{
			if (open1 == -1 && close1 == -1)
			{
				int temp2 = getNumber(str, start+1);
				Knot* newKnot2 = new Knot();
				newKnot2->set_value(temp2);
				if(temp2 < knot->get_value())
					knot->set_left(newKnot2);
				else
					knot->set_right(newKnot2);
			}
			else
			{
				if (open2 == -1 && close2 == -1)
				{
					int temp2 = getNumber(str, start+1);
					Knot* newKnot2 = new Knot();
					newKnot2->set_value(temp2);
					if(temp2 < knot->get_value())
						knot->set_left(newKnot2);
					else
						knot->set_right(newKnot2);

					onlyPre(newKnot2, str, open1, close1);
				}
				else
				{
					int temp = getNumber(str, start+1);
					Knot* newKnot = new Knot();
					newKnot->set_value(temp);

					if (temp < knot->get_value())
					{
						knot->set_left(newKnot);
					}
					else if (knot->get_value() < temp)
					{
						knot->set_right(newKnot);
					}
					onlyPre(newKnot, str, open1, close1);
					onlyPre(newKnot, str, open2, close2);
				}
			}
		}
	}
}

int RebuildTree::getNumber(string str, int start, int stop)
{
	string temp = "";
	for (int i=start; i<=stop; ++i)
	{
		temp += str[i];
	}
	return stoi(temp);
}

int RebuildTree::getNumber(string str, int start)
{
	string temp = "";
	while(str[start] != ',')
	{
		temp += str[start];
		start++;
	}
	return stoi(temp);
}

void RebuildTree::findBrackets(string str, int start, int stop, int& open1, int& close1, int& open2, int& close2)
{
	open1 =-1;
	close1=-1;
	open2 =-1;
	close2=-1;

	int bracketCnt=0;
	for(int i=start+1; i<stop; ++i)
	{
		if(str[i] == ')')
		{
			bracketCnt--;
		}

		if (str[i] == '(' || str[i] == ')')
		{
			if (bracketCnt == 0 && open1 == -1)
			{
				open1 = i;
			}
			else if (bracketCnt == 0  && close1 == -1)
			{
				close1 = i;
			}
			else if (bracketCnt == 0 && open2 == -1)
			{
				open2 = i;
			}
			else if (bracketCnt == 0 && close2 == -1)
			{
				close2 = i;
			}
		}

		if(str[i] == '(')
		{
			bracketCnt++;
		}
	}
}
