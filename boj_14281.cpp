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
	vector<long long> vecNum(iN, 0);
	for (int i = 0; i < iN; ++i) cin >> vecNum[i];

	long long lAns = 0;
	while (true)
	{
		bool bChanged = false;
		for (int i = 1; i < iN - 1; ++i)
		{
			long long lSum = vecNum[i - 1] + vecNum[i + 1];
			long long lDiff = (vecNum[i] * 2 - lSum + 1) / 2;
			if (lDiff > 0)
			{
				bChanged = true;
				lAns += lDiff;
				vecNum[i] -= lDiff;
			}
		}
		if (!bChanged) break;
	}
	cout << lAns << "\n";
	return 0;
}
