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

	vector<vector<string>> matWord(iM + 1, vector<string>());
	for (int i = 0;i < iN;++i)
	{
		string strWord;
		cin >> strWord;
		int iCount = 0;
		for (char ch : strWord)
		{
			if (ch == '0')
			{
				++iCount;
			}
		}
		matWord[iCount].push_back(strWord);
	}

	int iK;
	cin >> iK;

	int iAns = 0;
	while (iK >= 0)
	{
		if (iK > iM)
		{
			iK -= 2;
			continue;
		}

		int iMaxCount = 0;
		sort(matWord[iK].begin(), matWord[iK].end());
		if (matWord[iK].size() == 1)
		{
			iMaxCount = 1;
		}
		else if (matWord[iK].size() >= 2)
		{
			int iTempCount = 1;
			iMaxCount = 1;
			int iSize = matWord[iK].size();
			for(int j=1;j<iSize;++j)
			{
				if (matWord[iK][j - 1] == matWord[iK][j])
				{
					++iTempCount;
				}
				else
				{
					iTempCount = 1;
				}
				iMaxCount = max(iMaxCount, iTempCount);
			}
		}
		iAns = max(iAns, iMaxCount);
		iK -= 2;
	}

	cout << iAns << "\n";
	return 0;
}
