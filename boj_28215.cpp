#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iK;
	cin >> iN >> iK;

	vector<pair<int, int>> vecPos(iN, { 0,0 });
	for (int i = 0; i < iN; ++i)
	{
		cin >> vecPos[i].first >> vecPos[i].second;
	}

	int iAns = 1000000000;
	if (iK == 1)
	{
		for (int i = 0; i < iN; ++i)
		{
			int iTempMax = 0;
			for (int t = 0; t < iN; ++t)
			{
				iTempMax = max(iTempMax, abs(vecPos[t].first - vecPos[i].first) + abs(vecPos[t].second - vecPos[i].second));
			}
			iAns = min(iAns, iTempMax);
		}
	}
	else if (iK == 2)
	{
		for (int i = 0; i < iN; ++i)
		{
			for (int j = i + 1; j < iN; ++j)
			{
				int iTempMax = 0;
				for (int t = 0; t < iN; ++t)
				{
					int iTemp = 1000000000;
					iTemp = min(iTemp, abs(vecPos[t].first - vecPos[i].first) + abs(vecPos[t].second - vecPos[i].second));
					iTemp = min(iTemp, abs(vecPos[t].first - vecPos[j].first) + abs(vecPos[t].second - vecPos[j].second));
					iTempMax = max(iTempMax, iTemp);
				}
				iAns = min(iAns, iTempMax);
			}
		}
	}
	else
	{
		for (int i = 0; i < iN; ++i)
		{
			for (int j = i + 1; j < iN; ++j)
			{
				for (int k = j + 1; k < iN; ++k)
				{
					int iTempMax = 0;
					for (int t = 0; t < iN; ++t)
					{
						int iTemp = 1000000000;
						iTemp = min(iTemp, abs(vecPos[t].first - vecPos[i].first) + abs(vecPos[t].second - vecPos[i].second));
						iTemp = min(iTemp, abs(vecPos[t].first - vecPos[j].first) + abs(vecPos[t].second - vecPos[j].second));
						iTemp = min(iTemp, abs(vecPos[t].first - vecPos[k].first) + abs(vecPos[t].second - vecPos[k].second));
						iTempMax = max(iTempMax, iTemp);
					}
					iAns = min(iAns, iTempMax);
				}
			}
		}
	}

	cout << iAns << "\n";
	return 0;
}
