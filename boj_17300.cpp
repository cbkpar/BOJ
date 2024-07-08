#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iL;
	cin >> iL;

	vector<int> vecPattern(iL, 0);
	for (int i = 0;i < iL;++i)
	{
		cin >> vecPattern[i];
	}

	vector<bool> vecVisited(10, false);
	vecVisited[vecPattern[0]] = true;
	bool bPossible = true;

	for (int i = 1;i < iL;++i)
	{
		if (vecVisited[vecPattern[i]])
		{
			bPossible = false;
		}
		else
		{
			int iU = vecPattern[i - 1];
			int iV = vecPattern[i];
			if (iU > iV) swap(iU, iV);

			int iMid = 0;
			if (iU == 1 && iV == 3) iMid = 2;
			if (iU == 1 && iV == 7) iMid = 4;
			if (iU == 1 && iV == 9) iMid = 5;
			if (iU == 2 && iV == 8) iMid = 5;
			if (iU == 3 && iV == 7) iMid = 5;
			if (iU == 3 && iV == 9) iMid = 6;
			if (iU == 4 && iV == 6) iMid = 5;
			if (iU == 7 && iV == 9) iMid = 8;

			if (iMid > 0)
			{
				if (!vecVisited[iMid])
				{
					bPossible = false;
				}
			}
		}
		vecVisited[vecPattern[i]] = true;
	}

	cout << (bPossible ? "YES" : "NO") << "\n";
	return 0;
}
