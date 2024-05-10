#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iR, iC, iK;
	cin >> iR >> iC >> iK;

	vector<vector<int>> matNum(100, vector<int>(100, 0));
	for (int i = 0;i < 3;++i)
	{
		for (int j = 0;j < 3;++j)
		{
			cin >> matNum[i][j];
		}
	}

	int iNowR = 3;
	int iNowC = 3;

	--iR;
	--iC;

	int iNow = -1;
	for (int t = 0;t <= 100;++t)
	{
		if (matNum[iR][iC] == iK)
		{
			iNow = t;
			break;
		}

		vector<vector<int>> matTemp(100, vector<int>(100, 0));

		if (iNowR >= iNowC)
		{
			int iMaxR = 0;
			for (int i = 0;i < iNowR;++i)
			{
				vector<int> vecCount(101, 0);
				for (int j = 0;j < iNowC;++j)
				{
					++vecCount[matNum[i][j]];
				}
				vector<pair<int, int>> vecSort;
				for (int j = 1;j <= 100;++j)
				{
					if (vecCount[j] > 0)
					{
						vecSort.push_back({ j,vecCount[j] });
					}
				}
				sort(vecSort.begin(), vecSort.end(),
					[](const pair<int, int>& o1, const pair<int, int>& o2)->bool {
						if (o1.second == o2.second) return o1.first < o2.first;
						return o1.second < o2.second;
					});
				int iTempR = vecSort.size();
				if (iTempR > 50) iTempR = 50;
				iMaxR = max(iMaxR, iTempR * 2);
				for (int j = 0;j < iTempR;++j)
				{
					matTemp[i][j * 2] = vecSort[j].first;
					matTemp[i][j * 2 + 1] = vecSort[j].second;
				}
			}
			matNum = matTemp;
			iNowC = iMaxR;
		}
		else
		{
			int iMaxC = 0;
			for (int i = 0;i < iNowC;++i)
			{
				vector<int> vecCount(101, 0);
				for (int j = 0;j < iNowR;++j)
				{
					++vecCount[matNum[j][i]];
				}
				vector<pair<int, int>> vecSort;
				for (int j = 1;j <= 100;++j)
				{
					if (vecCount[j] > 0)
					{
						vecSort.push_back({ j,vecCount[j] });
					}
				}
				sort(vecSort.begin(), vecSort.end(),
					[](const pair<int, int>& o1, const pair<int, int>& o2)->bool {
						if (o1.second == o2.second) return o1.first < o2.first;
						return o1.second < o2.second;
					});
				int iTempC = vecSort.size();
				if (iTempC > 50) iTempC = 50;
				iMaxC = max(iMaxC, iTempC * 2);
				for (int j = 0;j < iTempC;++j)
				{
					matTemp[j * 2][i] = vecSort[j].first;
					matTemp[j * 2 + 1][i] = vecSort[j].second;
				}
			}
			matNum = matTemp;
			iNowR = iMaxC;
		}
	}

	cout << iNow << "\n";
	return 0;
}
