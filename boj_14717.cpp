#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> vecNum(21, 0);
	for (int i = 1; i <= 10; ++i)
	{
		vecNum[i] = vecNum[i + 10] = i;
	}

	int iN, iM;
	cin >> iN >> iM;

	int iScore = (iN + iM) % 10;
	if (iN == iM) iScore = iN * 10;
	vecNum[iN] = 0;
	vecNum[iM + 10] = 0;

	int iCount = 0;
	int iWin = 0;

	for (int i = 1; i <= 20; ++i)
	{
		for (int j = i + 1; j <= 20; ++j)
		{
			if (vecNum[i] == 0 || vecNum[j] == 0) continue;

			int p = i % 10;
			int q = j % 10;

			int iScore2 = (p + q) % 10;
			if (p == q) iScore2 = (p == 0 ? 10 : p) * 10;
			++iCount;
			if (iScore > iScore2) ++iWin;
		}
	}
	printf("%.3f\n", (float)(iWin) / iCount);
	return 0;
}
