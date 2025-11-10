#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iK;
	cin >> iN >> iK;

	vector<vector<int>> matNum(iK, vector<int>());
	vector<vector<int>> matAns(iK, vector<int>());
	for (int i = 0;i < iK;++i)
	{
		int iSize;
		cin >> iSize;
		matNum[i] = vector<int>(iSize, 0);
		matAns[i] = vector<int>(iSize, 0);
		for (int j = 0;j < iSize;++j)
		{
			cin >> matNum[i][j];
		}
		sort(matNum[i].begin(), matNum[i].end());
	}
	vector<int> vecPos(iK, 0);
	for (int i = 0;i < iN;++i)
	{
		for (int j = 0;j < iK;++j)
		{
			if (vecPos[j] >= matNum[j].size()) continue;
			if (i - vecPos[j] == matNum[j][vecPos[j]])
			{
				matAns[j][vecPos[j]] = i + 1;
				vecPos[j]++;
				break;
			}
		}
	}
	for (int i = 0;i < iK;++i)
	{
		for (int j = 0;j < matAns[i].size();++j)
		{
			cout << matAns[i][j] << (j == matAns[i].size() - 1 ? "\n" : " ");
		}
	}

	return 0;
}
