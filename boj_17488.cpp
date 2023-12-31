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

	vector<int> vecLimit(iM + 1, 0);
	for (int i = 1; i <= iM; ++i) cin >> vecLimit[i];

	vector<vector<int>> vecAns(iN, vector<int>());

	vector<vector<int>> vecFirst(iN, vector<int>());
	for (int i = 0; i < iN; ++i)
	{
		int iNum;
		while (true)
		{
			cin >> iNum;
			if (iNum == -1) break;
			vecFirst[i].push_back(iNum);
			--vecLimit[iNum];
		}
	}
	for (int i = 0; i < iN; ++i)
	{
		for (int iNum : vecFirst[i])
		{
			if (vecLimit[iNum] >= 0)
			{
				vecAns[i].push_back(iNum);
			}
		}
	}

	vector<vector<int>> vecSecond(iN, vector<int>());
	for (int i = 0; i < iN; ++i)
	{
		int iNum;
		while (true)
		{
			cin >> iNum;
			if (iNum == -1) break;
			vecSecond[i].push_back(iNum);
			--vecLimit[iNum];
		}
	}
	for (int i = 0; i < iN; ++i)
	{
		for (int iNum : vecSecond[i])
		{
			if (vecLimit[iNum] >= 0)
			{
				vecAns[i].push_back(iNum);
			}
		}
	}

	for (int i = 0; i < iN; ++i)
	{
		int iSize = vecAns[i].size();
		if (iSize > 0)
		{
			sort(vecAns[i].begin(), vecAns[i].end());
			for (int j = 0; j < iSize; ++j)
			{
				cout << vecAns[i][j] << (j == iSize - 1 ? "\n" : " ");
			}
		}
		else
		{
			cout << "망했어요" << "\n";
		}
	}
	return 0;
}
