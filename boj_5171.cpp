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

	vector<vector<string>> matMap(iN, vector<string>());
	for (int i = 0; i < iN; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			string strWord;
			cin >> strWord;
			matMap[i].push_back(strWord);
		}
	}

	for (int t = 1; t <= iM; ++t)
	{
		if (t > 1) cout << "\n";
		cout << "Data Set " << t << ":\n";

		vector<string> vecLine(5, "");
		for (int i = 0; i < 5; ++i)
		{
			cin >> vecLine[i];
		}

		int iMax = 0;
		for (int i = 0; i < iN; ++i)
		{
			int iTemp = 0;
			for (int j = 0; j < 5; ++j)
			{
				for (int k = 0; k < 5; ++k)
				{
					if (matMap[i][j][k] == vecLine[j][k])
					{
						++iTemp;
					}
				}
			}
			iMax = max(iMax, iTemp);
		}

		vector<int> vecAns;
		for (int i = 0; i < iN; ++i)
		{
			int iTemp = 0;
			for (int j = 0; j < 5; ++j)
			{
				for (int k = 0; k < 5; ++k)
				{
					if (matMap[i][j][k] == vecLine[j][k])
					{
						++iTemp;
					}
				}
			}
			if (iMax == iTemp)
			{
				vecAns.push_back(i + 1);
			}
		}

		int iSize = vecAns.size();
		for (int i = 0; i < iSize; ++i)
		{
			cout << vecAns[i] << (i == iSize - 1 ? "\n" : " ");
		}
	}

	return 0;
}
