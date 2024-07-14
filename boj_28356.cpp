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

	int iAns = 0;

	vector<vector<int>> matNum(iN + 2, vector<int>(iM + 2, 0));
	for (int i = 1; i <= iN; ++i)
	{
		for (int j = 1; j <= iM; ++j)
		{
			int iTemp = 1;
			for (int k = 1; k <= 3; ++k)
			{
				if (matNum[i - 1][j - 1] == k || matNum[i][j - 1] == k || matNum[i - 1][j] == k || matNum[i - 1][j + 1] == k)
				{
					++iTemp;
					continue;
				}
				break;
			}
			matNum[i][j] = iTemp;
			iAns = max(iAns, iTemp);
		}
	}

	cout << iAns << "\n";
	for (int i = 1; i <= iN; ++i)
	{
		for (int j = 1; j <= iM; ++j)
		{
			cout << matNum[i][j] << (j == iM ? "\n" : " ");
		}
	}
	return 0;
}
