#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;

	vector<pair<string, string>> vecName;

	for (int i = 0; i < iN; ++i)
	{
		string strName, strType;
		cin >> strName >> strType;
		if (strType == "-") continue;

		vecName.push_back({ strType, strName });
	}

	sort(vecName.begin(), vecName.end());

	string strBefore = "-";
	bool bPossible = false;

	vector<pair<string, string>> vecAns;

	int iSize = vecName.size();
	for (int i = 0; i < iSize; ++i)
	{
		if (vecName[i].first == strBefore)
		{
			if (bPossible)
			{
				if (i < iSize - 1)
				{
					if (vecName[i + 1].first != strBefore)
					{
						vecAns.push_back({ vecName[i - 1].second, vecName[i].second });
					}
				}
				else
				{
					vecAns.push_back({ vecName[i - 1].second, vecName[i].second });
				}
				bPossible = false;
			}
		}
		else
		{
			bPossible = true;
		}
		strBefore = vecName[i].first;
	}

	cout << vecAns.size() << "\n";
	for (int i = 0; i < vecAns.size(); ++i)
	{
		cout << vecAns[i].first << " " << vecAns[i].second << "\n";
	}
	return 0;
}
