#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);

	int iT;
	cin >> iT;
	while (iT-- > 0)
	{
		int iN;
		cin >> iN;
		vector<pair<string, int>> vecItem;

		for (int i = 0;i < iN;++i)
		{
			string strName;
			cin >> strName;

			int iCount;
			cin >> iCount;

			bool bFound = false;

			int iSize = vecItem.size();
			for (int j = 0;j < iSize;++j)
			{
				if (vecItem[j].first == strName)
				{
					vecItem[j].second += iCount;
					bFound = true;
					break;
				}
			}

			if (!bFound)
			{
				vecItem.push_back({ strName,iCount });
			}
		}

		sort(vecItem.begin(), vecItem.end(), [](const pair<string, int>& o1, const pair<string, int>& o2)->bool
			{
				if (o1.second != o2.second) return o1.second > o2.second;
				return o1.first.compare(o2.first) < 0;
			});

		int iSize = vecItem.size();
		cout << iSize << "\n";
		for (int i = 0;i < iSize;++i)
		{
			cout << vecItem[i].first << " " << vecItem[i].second << "\n";
		}
	}

	return 0;
}
