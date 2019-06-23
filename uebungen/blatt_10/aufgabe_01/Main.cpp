#include <iostream>
using namespace std;

#include "SkipList.h"

int main()
{
	SkipList skipi;

	for (int i = 0; i < 11; ++i)
	{
		skipi.insertX(i);
	}

	skipi.print();
	skipi.deleteX(0);
	skipi.print();

	return 0;
}
