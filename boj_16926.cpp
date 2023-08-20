#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iM, iR;
	cin >> iN >> iM >> iR;

	vector<vector<int>> matNum(iN, vector<int>(iM, 0));
	for (int i = 0; i < iN; ++i)
	{
		for (int j = 0; j < iM; ++j)
		{
			cin >> matNum[i][j];
		}
	}

	vector<vector<int>> matAns(iN, vector<int>(iM, 0));
	if (iN <= iM)
	{
		for (int t = 0; t < iN / 2; ++t)
		{
			vector<int> vecTemp;
			for (int i = t; i < iN - t - 1; ++i) vecTemp.push_back(matNum[i][t]);
			for (int i = t; i < iM - t - 1; ++i) vecTemp.push_back(matNum[iN - t - 1][i]);
			for (int i = iN - t - 1; i > t; --i) vecTemp.push_back(matNum[i][iM - t - 1]);
			for (int i = iM - t - 1; i > t; --i) vecTemp.push_back(matNum[t][i]);

			int iSize = vecTemp.size();
			int iIndex = iR * iSize - iR;

			for (int i = t; i < iN - t - 1; ++i) matAns[i][t] = (vecTemp[(iIndex++) % iSize]);
			for (int i = t; i < iM - t - 1; ++i) matAns[iN - t - 1][i] = (vecTemp[(iIndex++) % iSize]);
			for (int i = iN - t - 1; i > t; --i) matAns[i][iM - t - 1] = (vecTemp[(iIndex++) % iSize]);
			for (int i = iM - t - 1; i > t; --i) matAns[t][i] = (vecTemp[(iIndex++) % iSize]);
		}
	}
	else
	{
		for (int t = 0; t < iM / 2; ++t)
		{
			vector<int> vecTemp;
			for (int i = t; i < iN - t - 1; ++i) vecTemp.push_back(matNum[i][t]);
			for (int i = t; i < iM - t - 1; ++i) vecTemp.push_back(matNum[iN - t - 1][i]);
			for (int i = iN - t - 1; i > t; --i) vecTemp.push_back(matNum[i][iM - t - 1]);
			for (int i = iM - t - 1; i > t; --i) vecTemp.push_back(matNum[t][i]);

			int iSize = vecTemp.size();
			int iIndex = iR * iSize - iR;

			for (int i = t; i < iN - t - 1; ++i) matAns[i][t] = (vecTemp[(iIndex++) % iSize]);
			for (int i = t; i < iM - t - 1; ++i) matAns[iN - t - 1][i] = (vecTemp[(iIndex++) % iSize]);
			for (int i = iN - t - 1; i > t; --i) matAns[i][iM - t - 1] = (vecTemp[(iIndex++) % iSize]);
			for (int i = iM - t - 1; i > t; --i) matAns[t][i] = (vecTemp[(iIndex++) % iSize]);
		}
	}

	for (int i = 0; i < iN; ++i)
	{
		for (int j = 0; j < iM; ++j)
		{
			cout << matAns[i][j] << (j == iM - 1 ? "\n" : " ");
		}
	}
	return 0;
}
