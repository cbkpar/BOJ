#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;

	map<int, int> mapNum;

	vector<set<int>> matNum(101, set<int>());
	for (int i = 0;i < iN;++i)
	{
		int iP, iL;
		cin >> iP >> iL;
		mapNum[iP] = iL;
		matNum[iL].insert(iP);
	}

	int iM;
	cin >> iM;
	for (int i = 0;i < iM;++i)
	{
		string strCmd;
		cin >> strCmd;
		if (strCmd == "add")
		{
			int iP, iL;
			cin >> iP >> iL;
			mapNum[iP] = iL;
			matNum[iL].insert(iP);
		}
		else if (strCmd == "solved")
		{
			int iNum;
			cin >> iNum;
			int iLevel = mapNum[iNum];
			matNum[iLevel].erase(matNum[iLevel].find(iNum));
		}
		else if (strCmd == "recommend")
		{
			int iX;
			cin >> iX;
			if (iX == 1)
			{
				for (int iL = 100;iL >= 1;--iL)
				{
					if (matNum[iL].size() >= 1)
					{
						cout << *matNum[iL].rbegin() << "\n";
						break;
					}
				}
			}
			else
			{
				for (int iL = 1;iL <= 100;++iL)
				{
					if (matNum[iL].size() >= 1)
					{
						cout << *matNum[iL].begin() << "\n";
						break;
					}
				}
			}
		}
	}

	return 0;
}
