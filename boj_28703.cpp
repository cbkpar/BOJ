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

	vector<long long> vecNum(iN);
	for (int i = 0; i < iN; ++i) cin >> vecNum[i];

	long long lTempMax = -1;
	for (int i = 0; i < iN; ++i) lTempMax = max(lTempMax, vecNum[i]);

	for (int i = 0; i < iN; ++i)
	{
		while (true)
		{
			if (vecNum[i] * 2 > lTempMax) break;
			vecNum[i] *= 2;
		}
	}

	sort(vecNum.begin(), vecNum.end());
	long long lAns = vecNum[iN - 1] - vecNum[0];
	long long lMax = vecNum[iN - 1];

	for (int i = 0; i < iN - 1; ++i)
	{
		while (true)
		{
			if (vecNum[i] >= lTempMax) break;
			vecNum[i] *= 2;
		}
		lMax = max(lMax, vecNum[i]);
		lAns = min(lAns, lMax - vecNum[i + 1]);
	}
	cout << lAns << "\n";
	return 0;
}
