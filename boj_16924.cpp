#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iM;
	cin >> iN >> iM;

	vector<string> vecWord(iN, "");
	for (int i = 0;i < iN;++i) cin >> vecWord[i];

	vector<vector<int>> matCount(iN, vector<int>(iM, 0));
	vector<vector<bool>> matVisited(iN, vector<bool>(iM, false));
	int iTotalCount = 0;

	for (int i = 0;i < iN;++i)
	{
		for (int j = 0;j < iM;++j)
		{
			if (vecWord[i][j] == '*')
			{
				int iCount = 1;
				while (true)
				{
					int iTop = i - iCount;
					int iBottom = i + iCount;
					int iLeft = j - iCount;
					int iRight = j + iCount;
					if (iTop < 0 || iBottom > iN - 1 || iLeft < 0 || iRight > iM - 1)
					{
						break;
					}
					if (vecWord[iTop][j] != '*') break;
					if (vecWord[iBottom][j] != '*') break;
					if (vecWord[i][iLeft] != '*') break;
					if (vecWord[i][iRight] != '*') break;
					matVisited[iTop][j] = true;
					matVisited[iBottom][j] = true;
					matVisited[i][iLeft] = true;
					matVisited[i][iRight] = true;
					matVisited[i][j] = true;
					++iCount;
				}
				matCount[i][j] = iCount - 1;
				if (matCount[i][j] > 0) ++iTotalCount;
			}
		}
	}

	if (iTotalCount == 0)
	{
		cout << "-1" << "\n";
	}
	else
	{
		for (int i = 0;i < iN;++i)
		{
			for (int j = 0;j < iM;++j)
			{
				if (vecWord[i][j] == '*' && !matVisited[i][j])
				{
					cout << "-1" << "\n";
					return 0;
				}
			}
		}
		cout << iTotalCount << "\n";
		for (int i = 0;i < iN;++i)
		{
			for (int j = 0;j < iM;++j)
			{
				if (matCount[i][j] >= 1)
				{
					cout << (i + 1) << " " << (j + 1) << " " << matCount[i][j] << "\n";
				}
			}
		}
	}
	return 0;
}
