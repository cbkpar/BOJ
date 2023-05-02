#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

bool PrimeCheck(int iNum)
{
	if (iNum < 2) return false;
	int iSqrt = (int)sqrt(iNum);
	for (int i = 2; i <= iSqrt; ++i)
	{
		if (iNum % i == 0) return false;
	}
	return true;
}

bool ArrPrime[1000001] = { false, };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 2; i * i <= 1000000; i++) {
		for (int j = i * i; j <= 1000000; j += i) {
			ArrPrime[j] = true;
		}
	}

	int iNum;
	while (cin >> iNum)
	{
		if (iNum < 8)
		{
			cout << "Impossible.\n";
			continue;
		}
		int iA = iNum - 6;
		while (true)
		{
			if (PrimeCheck(iA)) break;
			--iA;
		}
		iNum -= iA;
		int iB = (iNum % 2) + 2;
		iNum -= iB;
		for (int i = 2; i < iNum; ++i)
		{
			if (!ArrPrime[i] && !ArrPrime[iNum - i])
			{
				cout << iA << " " << iB << " " << i << " " << (iNum - i) << "\n";
				break;
			}
		}
	}
	return 0;
}
