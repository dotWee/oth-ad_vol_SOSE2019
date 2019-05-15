#include "Stoppwatch.h"

#include <chrono>

using namespace std;

Stoppwatch::Stoppwatch()
{
}

Stoppwatch::~Stoppwatch()
{
}

void Stoppwatch::startWatch()
{
	start = chrono::steady_clock::now();
}

void Stoppwatch::haltWatch()
{
	end = chrono::steady_clock::now();
	diff = end - start;
}

double Stoppwatch::timeIn_ms()
{
	return chrono::duration<double, milli>(diff).count();
}
