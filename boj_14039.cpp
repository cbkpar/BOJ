#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<vector<int>> matNum(4, vector<int>(4, 0));
	for (int i = 0;i < 4;++i)
	{
		for (int j = 0;j < 4;++j)
		{
			cin >> matNum[i][j];
		}
	}

	vector<int> vecSum;

	for (int i = 0;i < 4;++i)
	{
		int iSum = 0;
		for (int j = 0;j < 4;++j)
		{
			iSum += matNum[i][j];
		}
		vecSum.push_back(iSum);
	}

	for (int i = 0;i < 4;++i)
	{
		int iSum = 0;
		for (int j = 0;j < 4;++j)
		{
			iSum += matNum[j][i];
		}
		vecSum.push_back(iSum);
	}

	bool bPossible = true;
	for (int i = 1;i < 8;++i)
	{
		if (vecSum[i] != vecSum[i - 1])
		{
			bPossible = false;
		}
	}

	cout << (bPossible ? "magic" : "not magic") << "\n";
	return 0;
}
