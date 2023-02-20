#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iH, iW, iN;
	cin >> iH >> iW >> iN;

	vector<pair<int, int>> vecSticker(iN, { 0,0 });
	for (int i = 0; i < iN; ++i)
	{
		cin >> vecSticker[i].first >> vecSticker[i].second;
	}

	int iMax = 0;
	for (int i = 0; i < iN; ++i)
	{
		for (int j = i + 1; j < iN; ++j)
		{
			bool bPossible = false;
			if (vecSticker[i].first + vecSticker[j].first <= iW && max(vecSticker[i].second, vecSticker[j].second) <= iH) bPossible = true;
			if (vecSticker[i].first + vecSticker[j].second <= iW && max(vecSticker[i].second, vecSticker[j].first) <= iH) bPossible = true;
			if (vecSticker[i].second + vecSticker[j].first <= iW && max(vecSticker[i].first, vecSticker[j].second) <= iH) bPossible = true;
			if (vecSticker[i].second + vecSticker[j].second <= iW && max(vecSticker[i].first, vecSticker[j].first) <= iH) bPossible = true;
			if (vecSticker[i].first + vecSticker[j].first <= iH && max(vecSticker[i].second, vecSticker[j].second) <= iW) bPossible = true;
			if (vecSticker[i].first + vecSticker[j].second <= iH && max(vecSticker[i].second, vecSticker[j].first) <= iW) bPossible = true;
			if (vecSticker[i].second + vecSticker[j].first <= iH && max(vecSticker[i].first, vecSticker[j].second) <= iW) bPossible = true;
			if (vecSticker[i].second + vecSticker[j].second <= iH && max(vecSticker[i].first, vecSticker[j].first) <= iW) bPossible = true;

			if (bPossible)
			{
				iMax = max(iMax, vecSticker[i].first * vecSticker[i].second + vecSticker[j].first * vecSticker[j].second);
			}
		}
	}

	cout << iMax << "\n";
	return 0;
}
