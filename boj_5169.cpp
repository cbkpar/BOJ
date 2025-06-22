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
		int iS, iP;
		cin >> iS >> iP;
		vector<int> vecNum(iS + 1, 0);
		for (int i = 0; i < iP; ++i)
		{
			int iA, iB;
			cin >> iA >> iB;
			vecNum[iA] += iB;
		}

		int iAns = -1;
		for (int i = 1; i <= iS; ++i)
		{
			bool bPossible = true;
			for (int j = 1; j <= iS; ++j)
			{
				if (i == j) continue;
				if (vecNum[i] <= vecNum[j] * 2)
				{
					bPossible = false;
				}
			}
			if (bPossible)
			{
				iAns = i;
			}
		}

		if (t > 1) cout << "\n";
		cout << "Data Set " << t << ":\n";
		if (iAns == -1)
		{
			cout << "No suspect." << "\n";
		}
		else
		{
			cout << iAns << "\n";
		}
	}

	return 0;
}
