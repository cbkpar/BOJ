#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;

	bool bZero = false;

	long long lAns = 0;

	vector<long long> vecNum(iN, 0);
	for (int i = 0;i < iN;++i)
	{
		cin >> vecNum[i];
		if (vecNum[i] == 0)
		{
			bZero = true;
		}
		lAns += vecNum[i];
	}
	sort(vecNum.begin(), vecNum.end());

	long long lMax = 0;
	if (vecNum[0] <= 0 && vecNum[1] <= 0)
	{
		long long lDiff = vecNum[0] * vecNum[1] * 2 - vecNum[0] - vecNum[1];
		lMax = max(lMax, lDiff);
	}
	if (vecNum[iN - 1] >= 0 && vecNum[iN - 2] >= 0)
	{
		long long lDiff = vecNum[iN - 1] * vecNum[iN - 2] * 2 - vecNum[iN - 1] - vecNum[iN - 2];
		lMax = max(lMax, lDiff);
	}

	lAns += lMax;
	cout << lAns << "\n";

	return 0;
}
