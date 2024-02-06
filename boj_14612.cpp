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

	vector<pair<int, int>> vecTable;

	while (iN--)
	{
		string strCommand;
		cin >> strCommand;

		if (strCommand == "order")
		{
			int iNum, iTime;
			cin >> iNum >> iTime;
			vecTable.push_back({ iNum, iTime });
		}
		else if (strCommand == "sort")
		{
			sort(vecTable.begin(), vecTable.end(), [](const pair<int, int>& o1, const pair<int, int>& o2)->bool
				{
					if (o1.second == o2.second) return o1.first - o2.first < 0;
					return o1.second - o2.second < 0;
				}
			);
		}
		else if (strCommand == "complete")
		{
			int iNum;
			cin >> iNum;
			
			for (auto iter = vecTable.begin();iter != vecTable.end();)
			{
				if ((*iter).first == iNum)
				{
					iter = vecTable.erase(iter);
				}
				else
				{
					++iter;
				}
			}
		}

		int iSize = vecTable.size();
		if(iSize == 0)
		{
			cout << "sleep" << "\n";
		}
		else
		{
			for (int i = 0;i < iSize;++i)
			{
				cout << vecTable[i].first << (i == iSize - 1 ? "\n" : " ");
			}
		}
	}
	return 0;
}
