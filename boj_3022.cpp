#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;

	map<string, int> mapCount;
	int iAns = 0;

	for (int i = 0; i < iN; ++i)
	{
		string strName;
		cin >> strName;

		int iSum = 0;
		for (auto iter : mapCount)
		{
			if (iter.first == strName) continue;
			iSum += iter.second;
		}
		if (mapCount[strName] > iSum)
		{
			++iAns;
		}

		mapCount[strName]++;
	}

	cout << iAns << "\n";
	return 0;

}
