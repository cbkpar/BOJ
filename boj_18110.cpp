#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;

	if (iN == 0)
	{
		cout << "0\n";
		return 0;
	}

	vector<int> vecScore(31, 0);
	for (int i = 0; i < iN; ++i)
	{
		int iScore;
		cin >> iScore;
		++vecScore[iScore];
	}

	int iDelete = (iN * 15 + 50) / 100;
	int iTemp = iDelete;
	for (int i = 1; i <= 30; ++i)
	{
		while (vecScore[i] > 0)
		{
			if (iTemp == 0) break;
			--vecScore[i];
			--iTemp;
		}
	}
	iTemp = iDelete;
	for (int i = 30; i >= 1; --i)
	{
		while (vecScore[i] > 0)
		{
			if (iTemp == 0) break;
			--vecScore[i];
			--iTemp;
		}
	}
	int iSum = 0;
	int iCount = 0;
	for (int i = 1; i <= 30; ++i)
	{
		iSum += i * vecScore[i];
		iCount += vecScore[i];
	}
	int iScore = iSum / iCount;
	iSum %= iCount;
	if (iSum * 2 >= iCount) ++iScore;
	cout << iScore << "\n";
	return 0;
}
