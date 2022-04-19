#include <iostream>
#include <math.h>

using namespace std;

bool isPrime(long long& _llNumber)
{
	if (1 == _llNumber)
	{
		return false;
	}
	long long llSqrt = (long)sqrt(_llNumber);
	for (long long i = 2; i <= llSqrt; ++i)
	{
		if (0 == _llNumber%i)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	long long llN;
	cin >> llN;
	if (!isPrime(llN))
	{
		cout << "no" << endl;
		return 0;
	}
	long long llReversedN;
	llReversedN = 0;
	while (llN)
	{
		llReversedN *= 10;
		int iRest = llN % 10;
		if (3 == iRest || 4 == iRest || 7 == iRest)
		{
			cout << "no" << endl;
			return 0;
		}
		if (6 == iRest) {
			llReversedN += 9;
		}
		else if (9 == iRest)
		{
			llReversedN += 6;
		}
		else
		{
			llReversedN += iRest;
		}
		llN /= 10;
	}
	cout << (isPrime(llReversedN) ? "yes" : "no") << endl;
	return 0;
}
