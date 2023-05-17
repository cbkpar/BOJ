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
	int iIndex = 1;
	vector<vector<int>> matNum(iN, vector<int>(iN, 0));
	for (int i = 0; i < iN; ++i)
	{
		if (i % 2 == 0)
		{
			for (int j = 0; j < iN; ++j)
			{
				matNum[i][j] = iIndex++;
			}
		}
		else
		{
			for (int j = iN - 1; j >= 0; --j)
			{
				matNum[i][j] = iIndex++;
			}

		}
	}
	for (int i = 0; i < iN; ++i)
	{
		for (int j = 0; j < iN; ++j)
		{
			cout << matNum[i][j] << (j == iN - 1 ? "\n" : " ");
		}
	}
	return 0;
}
