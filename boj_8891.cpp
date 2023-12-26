#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iCount = 1;
	vector<pair<int, int>> vecNum(10001, { 0,0 });

	for (int i = 1;i <= 200;++i)
	{
		for (int j = 1;j <= i;++j)
		{
			if (iCount > 10000) break;
			vecNum[iCount++] = { j,i - j + 1 };
		}
	}

	int iT;
	cin >> iT;
	while (iT--)
	{
		int iA, iB;
		cin >> iA >> iB;

		int iX = vecNum[iA].first + vecNum[iB].first;
		int iY = vecNum[iA].second + vecNum[iB].second;

		int iAns = (iX + iY - 1) * (iX + iY - 2) / 2 + iX;
		cout << iAns << "\n";
	}
	return 0;
}
