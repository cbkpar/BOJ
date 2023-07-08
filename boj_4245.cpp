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

	while (true)
	{
		int iN;
		cin >> iN;
		if (iN == 0) break;
		vector<vector<int>> vecOrder(iN, vector<int>(5,0));
		for (int i = 0; i < iN; ++i)
		{
			string strWord;
			cin >> strWord;
			for (int j = 0; j < 5; ++j)
			{
				vecOrder[i][strWord[j] - 'A'] = j;
			}
		}
		int iMax = 1000000000;
		vector<int> vecTemp(5, 0);
		vector<int> vecAns(5, 0);
		for (int i = 0; i < 15625; ++i)
		{
			int iTemp = i;
			for (int j = 4; j >= 0; --j)
			{
				vecTemp[j] = iTemp % 5;
				iTemp /= 5;
			}
			bool bPossible = true;
			for (int p = 0; p < 5; ++p)
			{
				for (int q = 0; q < 5; ++q)
				{
					if (p == q) continue;
					if (vecTemp[p] == vecTemp[q]) bPossible = false;
				}
			}
			if (bPossible)
			{
				int iSum = 0;
				for (int p = 0; p < 5; ++p)
				{
					for (int q = 0; q < 5; ++q)
					{
						if (p == q) continue;
						for (int r = 0; r < iN; ++r)
						{
							if (vecTemp[p] > vecTemp[q] && vecOrder[r][p] < vecOrder[r][q]) ++iSum;
						}
					}
				}
				if (iSum < iMax)
				{
					iMax = iSum;
					for (int j = 0; j < 5; ++j)
					{
						vecAns[j] = vecTemp[j];
					}
				}
			}
		}
		string strAns = "ABCDE";
		for (int i = 0; i < 5; ++i)
		{
			strAns[vecAns[i]] = (char)(i + 'A');
		}
		cout << strAns << " is the median ranking with value " << iMax << ".\n";
	}
	return 0;
}
