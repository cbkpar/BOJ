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
	int iTotal = 0;
	for (int i = 1; i <= iN; ++i)
	{
		iTotal += 1 << i;
	}
	iTotal += 2;

	long long lAns = 0;

	vector<long long> vecNum(iTotal, 0);
	for (int i = 2; i < iTotal; ++i)
	{
		cin >> vecNum[i];
		lAns += vecNum[i];
	}

	long long lMax = 0;
	for (int i = 2; i < iTotal; ++i)
	{
		int iNext = i * 2;
		if (iNext >= iTotal)
		{
			lMax = max(lMax, vecNum[i]);
			continue;
		}

		vecNum[iNext] += vecNum[i];
		vecNum[iNext + 1] += vecNum[i];
	}

	for (int i = iTotal - 1; i >= 2; --i)
	{
		if (i * 2 >= iTotal)
		{
			vecNum[i] = lMax - vecNum[i];
			continue;
		}

		vecNum[i] = min(vecNum[i * 2], vecNum[i * 2 + 1]);
		vecNum[i * 2] -= vecNum[i];
		vecNum[i * 2 + 1] -= vecNum[i];
	}

	for (int i = 2; i < iTotal; ++i)
	{
		lAns += vecNum[i];
	}

	cout << lAns << "\n";
	return 0;
}
