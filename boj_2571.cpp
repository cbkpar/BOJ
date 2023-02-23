#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<vector<int>> matMap(101, vector<int>(101, 0));

	int iN;
	cin >> iN;
	while (iN--)
	{
		int iR, iC;
		cin >> iR >> iC;
		for (int i = iR; i < iR + 10; ++i)
		{
			for (int j = iC; j < iC + 10; ++j)
			{
				matMap[i][j] = 1;
			}
		}
	}

	vector<vector<int>> matSum(101, vector<int>(101, 0));
	for (int i = 1; i <= 100; ++i)
	{
		for (int j = 1; j <= 100; ++j)
		{
			matSum[i][j] = matSum[i - 1][j] + matSum[i][j - 1] - matSum[i - 1][j - 1] + matMap[i][j];
		}
	}

	int iAns = 100;
	for (int i = 1; i <= 100; ++i)
	{
		for (int j = 1; j <= 100; ++j)
		{
			if (matMap[i][j] == 0) continue;
			for (int s = i; s <= 100; ++s)
			{
				for (int e = j; e <= 100; ++e)
				{
					int iSum = matSum[s][e] - matSum[i - 1][e] - matSum[s][j - 1] + matSum[i - 1][j - 1];
					if (iSum == (s - i + 1) * (e - j + 1) && iSum > iAns)
					{
						iAns = iSum;
					}
				}
			}
		}
	}
	cout << iAns << "\n";
	return 0;
}
