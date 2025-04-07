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

	vector<vector<long long>> matHeight(iN, vector<long long>(iM, 0));
	for (int i = 0;i < iN;++i)
	{
		for (int j = 0;j < iM;++j)
		{
			cin >> matHeight[i][j];
		}
	}

	long long lSum = 0;
	for (int i = 1;i < iN - 1;++i)
	{
		for (int j = 1;j < iM - 1;++j)
		{
			long long lMax = matHeight[i][j] - 1;
			if (lMax < 0) lMax = 0;
			lMax = min(lMax, matHeight[i - 1][j]);
			lMax = min(lMax, matHeight[i + 1][j]);
			lMax = min(lMax, matHeight[i][j - 1]);
			lMax = min(lMax, matHeight[i][j + 1]);
			lSum += lMax;
		}
	}

	cout << lSum << "\n";
	return 0;
}
