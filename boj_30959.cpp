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

	vector<int> vecAns(iM, 0);
	for (int i = 0;i < iM;++i) cin >> vecAns[i];

	vector<vector<int>> vecNum(iN, vector<int>(iM, 0));
	for (int i = 0;i < iN;++i)
	{
		for (int j = 0;j < iM;++j)
		{
			cin >> vecNum[i][j];
		}
	}

	int iCountSingle = 0;
	int iCountMulti = 0;

	for (int i = 0;i < iN;++i)
	{
		int iCount = 0;
		for (int j = 0;j < iM;++j)
		{
			if (vecAns[j] == vecNum[i][j])
			{
				++iCount;
			}
		}
		iCountSingle = max(iCountSingle, iCount);
	}

	for (int i = 0;i < (1 << iN);++i)
	{
		vector<int> vecTemp(iM, 0);
		int iCount = 0;
		int iTeam = 0;
		for (int j = 0;j < iN;++j)
		{
			if ((i & (1 << j)) == (1 << j))
			{
				++iTeam;
				for (int k = 0;k < iM;++k)
				{
					if (vecNum[j][k] == 1)
					{
						++vecTemp[k];
					}
					else
					{
						--vecTemp[k];
					}
				}
			}
		}
		if (iTeam % 2 == 0) continue;
		for (int j = 0;j < iM;++j)
		{
			if (vecTemp[j] > 0)
			{
				vecTemp[j] = 1;
			}
			else
			{
				vecTemp[j] = 0;
			}
			if (vecAns[j] == vecTemp[j])
			{
				++iCount;
			}
		}
		iCountMulti = max(iCountMulti, iCount);
	}
	if (iCountMulti > iCountSingle)
	{
		cout << "1" << "\n";
	}
	else
	{
		cout << "0" << "\n";
	}
	return 0;
}
