#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector<int> CalcLength(const string& strWord, int iK)
{
	vector<int> vecAns(2, 0);
	vecAns[0] = 1000000000;
	vecAns[1] = 0;
	vector<vector<int>> vecIndex(26);

	int iCount = 0;
	int iLen = strWord.length();
	for (int i = 0; i < iLen; ++i)
	{
		vecIndex[strWord[i] - 'a'].push_back(i);
	}

	for (int i = 0; i < 26; ++i)
	{
		int iSize = vecIndex[i].size();
		for (int j = iK - 1; j < iSize; ++j)
		{
			vecAns[0] = min(vecAns[0], vecIndex[i][j] - vecIndex[i][j - iK + 1] + 1);
			vecAns[1] = max(vecAns[1], vecIndex[i][j] - vecIndex[i][j - iK + 1] + 1);
		}
	}
	return vecAns;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iT;
	cin >> iT;
	while (iT--)
	{
		string strWord;
		cin >> strWord;
		int iK;
		cin >> iK;

		vector<int> vecAns = CalcLength(strWord, iK);
		if (vecAns[0] == 1000000000 || vecAns[1] == 0)
		{
			cout << "-1\n";
		}
		else
		{
			cout << vecAns[0] << " " << vecAns[1] << "\n";
		}
	}

	return 0;
}
