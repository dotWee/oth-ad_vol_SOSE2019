#ifndef NAIVESEARCH_H_
#define NAIVESEARCH_H_

class NaiveSearch
{
public:
	NaiveSearch();
	virtual ~NaiveSearch();
	int naivSearch(const char *text, int textLength, const char *pattern, int patternLength);
};

#endif /* NAIVESEARCH_H_ */
