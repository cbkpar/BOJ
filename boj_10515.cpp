#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iT;
	cin >> iT;
	for (int t = 1; t <= iT; ++t)
	{
		int iD, iK, iS;
		cin >> iD >> iK >> iS;
		bool bPossible = true;
		vector<int> vecRoute(iS + 2, 0);
		vecRoute[iS + 1] = iD;
		for (int i = 1; i <= iS; ++i) cin >> vecRoute[i];
		vector<int> vecAns;

		int iNow = 0;
		while (true)
		{
			if (iNow >= iS + 1) break;
			if (vecRoute[iNow] + iK < vecRoute[iNow + 1])
			{
				bPossible = false;
				break;
			}
			int iNext = iNow + 1;
			while (iNext <= iS && vecRoute[iNow] + iK >= vecRoute[iNext + 1])
			{
				++iNext;
			}
			if (iNext < iS + 1)
			{
				vecAns.push_back(vecRoute[iNext]);
			}
			iNow = iNext;
		}

		cout << "Case #" << t << ":";
		if (bPossible)
		{
			for (int iDist : vecAns)
			{
				cout << " " << iDist;
			}
		}
		else
		{
			cout << " out of petrol";
		}
		cout << "\n";
	}
	return 0;
}
