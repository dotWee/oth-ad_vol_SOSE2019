#ifndef BOYERMOORESEARCH_H_
#define BOYERMOORESEARCH_H_

class BoyerMooreSearch
{
private:
	int getIndex(char c);
public:
	BoyerMooreSearch();
	virtual ~BoyerMooreSearch();
	int search(const char* text, int textLength, const char* pattern, int patternLength);
};

#endif /* BOYERMOORESEARCH_H_ */
