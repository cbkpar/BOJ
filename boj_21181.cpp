#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long CalcDist(long long lA, long long lB)
{
	return (lA - lB) * (lA - lB);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;

	vector<long long> vecPos(iN, 0);
	for (int i = 0;i < iN;++i)
	{
		cin >> vecPos[i];
	}

	long long lAns = 1000000000000L;
	for (int i = 0;i < iN;++i)
	{
		for (int j = i + 1;j < iN;++j)
		{
			long long lSum = 0;
			for (int k = 0;k < iN;++k)
			{
				lSum += min(CalcDist(vecPos[i], vecPos[k]), CalcDist(vecPos[j], vecPos[k]));
			}
			lAns = min(lAns, lSum);
		}
	}
	
	cout << lAns << "\n";
	return 0;
}
