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

	int iT;
	cin >> iT;
	for (int t = 1; t <= iT; ++t)
	{
		int iN, iM;
		cin >> iN >> iM;

		vector<pair<string, int>> vecCandidate(iN, { "",0 });
		for (int i = 0; i < iN; ++i)
		{
			cin >> vecCandidate[i].first;
		}
		while (iM--)
		{
			string strX, strC;
			int iCount;
			cin >> strX >> iCount >> strC;
			for (int i = 0; i < iN; ++i)
			{
				if (strX == vecCandidate[i].first)
				{
					vecCandidate[i].second += iCount;
				}
			}
		}
		int iIndex = -1;
		int iMax = -1;
		int iSame = 0;
		for (int i = 0; i < iN; ++i)
		{
			if (vecCandidate[i].second > iMax)
			{
				iIndex = i;
				iMax = vecCandidate[i].second;
				iSame = 1;
			}
			else if (vecCandidate[i].second == iMax)
			{
				iSame += 1;
			}
		}
		cout << "VOTE " << t << ": ";
		if (iSame == 1)
		{
			cout << "THE WINNER IS " << vecCandidate[iIndex].first << " " << iMax << "\n";
		}
		else
		{
			cout << "THERE IS A DILEMMA\n";
		}
	}
	return 0;
}
