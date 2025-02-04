#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iTotal = 0;

	int iN, iM;
	cin >> iN >> iM;

	map<int, int> mapCount;

	for (int i = 0;i < iN;++i)
	{
		int iK;
		cin >> iK;
		for (int j = 0;j < iK;++j)
		{
			int iNum;
			cin >> iNum;
			mapCount[iNum] = mapCount[iNum] + 1;
			if (mapCount[iNum] == iM)
			{
				++iTotal;
			}
		}
	}

	cout << iTotal << "\n";
	return 0;
}
