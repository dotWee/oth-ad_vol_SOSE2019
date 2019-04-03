#ifndef MAXSUM1D_H_
#define MAXSUM1D_H_

#include <vector>

class MaxSum1D
{
  private:
	int length;
	std::vector<int> line;

  public:
	MaxSum1D(int length);
	virtual ~MaxSum1D();
	int get_length();
	int calcSum(std::vector<int> value);
	void resetLine();
};

#endif /* MAXSUM1D_H_ */