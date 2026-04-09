#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);

	int iN, iM;
	cin >> iN >> iM;

	vector<vector<int>> matScore(iN, vector<int>(iM, 0));
	vector<int> vecMax(iN, 0);
	for (int i = 0;i < iN;++i)
	{
		for (int j = 0;j < iM;++j)
		{
			cin >> matScore[i][j];
			vecMax[i] = max(vecMax[i], matScore[i][j]);
		}
	}

	for (int i = 0;i < iM;++i)
	{
		int iCount = 0;
		for (int j = 0;j < iN;++j)
		{
			if (matScore[j][i] < vecMax[j])
			{
				++iCount;
			}
		}
		cout << iCount << (i == iM - 1 ? "\n" : " ");
	}

	return 0;
}
