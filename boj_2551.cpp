#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;

	vector<long long> vecCount(10001, 0);
	for (int i = 0; i < iN; ++i)
	{
		int iNum;
		cin >> iNum;
		++vecCount[iNum];
	}

	long long lTemp = 0;
	for (int i = 1; i <= 10000; ++i)
	{
		lTemp += vecCount[i];
		if (lTemp >= (iN + 1) / 2)
		{
			cout << i << " ";
			break;
		}
	}

	long long lAns = 10000;
	long long lMax = 1000000000000000000LL;
	for (long long i = 1; i <= 10000; ++i)
	{
		long long lSum = 0;
		for (long long j = 1; j <= 10000; ++j)
		{
			lSum += (j - i) * (j - i) * vecCount[j];
		}
		if (lSum < lMax)
		{
			lAns = i;
			lMax = lSum;
		}
	}
	cout << lAns << "\n";
	return 0;
}
