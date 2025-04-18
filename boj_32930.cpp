#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iM;
	cin >> iN >> iM;

	vector<pair<int, int>> vecPos;
	for (int i = 0; i < iN; ++i)
	{
		int iR, iC;
		cin >> iR >> iC;
		vecPos.push_back({ iR,iC });
	}

	int iNowR = 0;
	int iNowC = 0;
	int iAns = 0;

	for (int i = 0; i < iM; ++i)
	{
		int iMax = -1;
		int iIndex = 0;
		for (int j = 0; j < iN; ++j)
		{
			int iDiffR = abs(iNowR - vecPos[j].first);
			int iDiffC = abs(iNowC - vecPos[j].second);
			int iDiff = iDiffR * iDiffR + iDiffC * iDiffC;
			if (iDiff > iMax)
			{
				iMax = iDiff;
				iIndex = j;
			}
		}

		iNowR = vecPos[iIndex].first;
		iNowC = vecPos[iIndex].second;
		iAns += iMax;
		vecPos.erase(vecPos.begin() + iIndex);

		int iR, iC;
		cin >> iR >> iC;
		vecPos.push_back({ iR,iC });
	}

	cout << iAns << "\n";
	return 0;
}
