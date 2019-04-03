#ifndef MAXSUM2D_H_
#define MAXSUM2D_H_

#include <vector>

class MaxSum2D
{
  private:
	std::vector<std::vector<int>> field;
	int maxSum;
	int lines, rows;

  public:
	MaxSum2D(int lines, int rows);
	virtual ~MaxSum2D();
	void calcMaxSum();
	int get_MaxSum();
	void set_field(std::vector<std::vector<int>> field);
};

#endif /* MAXSUM2D_H_ */
