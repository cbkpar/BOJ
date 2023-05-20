#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long CalcXOR(long long lNum)
{
	long long lRet = 0;
	for (long long i = 0; i <= 60; ++i)
	{
		long long lTemp = lNum % (1LL << (i + 2));
		long long lPow = 1LL << i;
		long long lSum = 0;
		if (lTemp >= lPow)
		{

			if (min(lPow - 1, lTemp - lPow) % 2 == 0)
			{
				lSum = (lSum + 1) % 2;
			}
		}
		if (lTemp >= lPow * 3)
		{
			if (min(lPow - 1, lTemp - lPow * 3) % 2 == 0)
			{
				lSum = (lSum + 1) % 2;
			}
		}
		if (lSum == 1)
		{
			lRet += 1LL << i;
		}
	}
	return lRet;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long lA, lB;
	cin >> lA >> lB;

	long long lSum = CalcXOR(lA - 1) ^ CalcXOR(lB);
	cout << lSum << "\n";
	return 0;
}
