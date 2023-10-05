#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iM;
	cin >> iN >> iM;

	vector<int> vecC(iN, 0);
	vector<int> vecT(iN, 0);
	vector<int> vecP(iN, 0);
	vector<int> vecTime(iM, 0);
	vector<int> vecSum(iN, 0);

	for (int i = 0; i < iN; ++i)
	{
		cin >> vecC[i] >> vecT[i] >> vecP[i];
	}

	for (int i = 0; i < iM; ++i)
	{
		cin >> vecTime[i];
	}

	int iAns = -1;
	int iMax = 1000000000;

	for (int i = 0; i < iN; ++i)
	{
		vecSum[i] = vecC[i] * 100;
		for (int j = 0; j < iM; ++j)
		{
			if (vecTime[j] < vecT[i]) continue;
			vecSum[i] += (vecTime[j] + vecT[i] - 1) / vecT[i] * vecP[i];
		}
		if (vecSum[i] < iMax)
		{
			iAns = i + 1;
			iMax = vecSum[i];
		}
	}

	cout << iAns << "\n";
	return 0;
}
