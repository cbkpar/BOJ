#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long gcd(long long lA, long long lB)
{
	if (lB % lA == 0) return lA;
	return gcd(lB % lA, lA);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long lN, lB;
	cin >> lN >> lB;

	long long lSumX = 0;
	long long lSumY = 0;

	for (long long i = 0; i < lN; ++i)
	{
		long long lX, lY;
		cin >> lX >> lY;
		lSumX += lX;
		lSumY += lY;
	}

	if (lSumX == 0)
	{
		cout << "EZPZ\n";
	}
	else if (lSumY - lN * lB == 0)
	{
		cout << "0\n";
	}
	else
	{
		bool bMinus = false;
		long long lTempA = lSumY - lN * lB;
		long long lTempB = lSumX;
		if (lTempA < 0)
		{
			bMinus = !bMinus;
			lTempA *= -1;
		}
		if (lTempB < 0)
		{
			bMinus = !bMinus;
			lTempB *= -1;
		}
		long long lGCD = (lTempA < lTempB ? gcd(lTempA, lTempB) : gcd(lTempB, lTempA));
		lTempA /= lGCD;
		lTempB /= lGCD;
		cout << (bMinus ? "-" : "") << lTempA;
		if (lTempB != 1) cout << "/" << lTempB;
		cout << "\n";
	}
	return 0;
}
