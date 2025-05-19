#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long gcd(long long lA, long long lB)
{
	if (lB % lA == 0) return lA;
	return gcd(lB%lA, lA);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;

	vector<long long> vecA(iN, 0);
	vector<long long> vecB(iN, 0);

	for (int i = 0;i < iN;++i)
	{
		cin >> vecA[i];
	}
	for (int i = 0;i < iN;++i)
	{
		cin >> vecB[i];
	}

	for (int i = 0;i < iN;++i)
	{
		long long lGCD = gcd(vecA[i], vecB[i]);
		vecA[i] /= lGCD;
		vecB[i] /= lGCD;
	}

	long long lMaxA = 1999999999;
	long long lMaxB = 1;

	for (int i = 0;i < iN;++i)
	{
		if (lMaxB * vecA[i] < vecB[i] * lMaxA)
		{
			lMaxA = vecA[i];
			lMaxB = vecB[i];
		}
	}

	int iAns = 0;
	int iNow = 0;
	for (int i = 0;i < iN;++i)
	{
		if (vecA[i] == lMaxA && vecB[i] == lMaxB)
		{
			++iNow;
		}
		else
		{
			iNow = 0;
		}
		iAns = max(iAns, iNow);
	}

	cout << lMaxB << " " << lMaxA << "\n";
	cout << iAns << "\n";
	return 0;
}
