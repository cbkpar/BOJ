#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int iN;
	cin >> iN;

	vector<int> vecNum(iN, 0);
	vector<bool> vecVisited(iN, false);
	for (int i = 0;i < iN;++i) cin >> vecNum[i];

	sort(vecNum.begin(), vecNum.end());

	int iAns = 0;
	for (int t = 0;t < 2;++t)
	{
		int iMax = -1;
		for (int i = 0;i < iN;++i)
		{
			if (vecVisited[i]) continue;
			if (vecNum[i] > iMax)
			{
				++iAns;
				iMax = vecNum[i];
				vecVisited[i] = true;
			}
		}
	}

	cout << iAns << "\n";
	return 0;
}
