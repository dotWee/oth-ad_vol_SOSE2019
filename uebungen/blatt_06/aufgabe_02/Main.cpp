#include <iostream>
#include <ctime>
#include "Matrix.h"
#include "Stoppwatch.h"

using namespace std;

int main()
{
	Stoppwatch timerOld, timerNew;

	int m_n = 8;

	do
	{
		Matrix M(m_n, m_n);
		Matrix N(m_n, m_n);
		Matrix O(m_n, m_n);
		Matrix O2(m_n, m_n);

		M.fillRND();
		N.fillRND();

		timerNew.startWatch();
		O = M.Mult(N);
		timerNew.haltWatch();

		timerOld.startWatch();
		O2 = M.Mult_Old(N);
		timerOld.haltWatch();

		cout << m_n << " newTime: " << timerNew.timeIn_ms() << " oldTime: " << timerOld.timeIn_ms() << " Diff new-old: " << timerNew.timeIn_ms() - timerOld.timeIn_ms() << endl;
		m_n = 2 * m_n;
	} while (!(timerNew.timeIn_ms() < timerOld.timeIn_ms()));

	cout << "Ab " << m_n / 2 << " war neue Variante schneller" << endl;

	return 0;
}
