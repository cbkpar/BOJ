#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;

	vector<pair<int, string>> vecUniv(6, { 0,"" });
	for (int i = 0; i < 6; ++i)
	{
		cin >> vecUniv[i].second;
		int iPt, iPu, iRt, iRu, iF;
		cin >> iPt >> iPu >> iRt >> iRu >> iF;
		int iScore = iRu * 56 + iRt * 24 + iPu * 14 + iPt * 6 + iF * 30;
		vecUniv[i].first = iScore;
	}
	sort(vecUniv.begin(), vecUniv.end(), greater<>());
	for (int i = 0; i < 6; ++i)
	{
		if (vecUniv[i].second == "Taiwan")
		{
			int iSum = (iN - 1) / 6;
			if ((iN - 1) % 6 >= i) ++iSum;
			cout << iSum << "\n";
		}
	}
	return 0;
}
