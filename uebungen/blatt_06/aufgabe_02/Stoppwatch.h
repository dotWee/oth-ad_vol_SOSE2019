#ifndef STOPPWATCH_H_
#define STOPPWATCH_H_

#include <chrono>

class Stoppwatch
{
private:
	std::chrono::steady_clock::time_point start;
	std::chrono::steady_clock::time_point end;
	std::chrono::steady_clock::duration diff;
public:
	Stoppwatch();
	virtual ~Stoppwatch();
	void startWatch();
	void haltWatch();
	double timeIn_ms();
};

#endif /* STOPPWATCH_H_ */