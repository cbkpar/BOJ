#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iK;
	cin >> iN >> iK;
	int iWR, iWC;
	cin >> iWR >> iWC;
	bool IsBlocked[9] = { false, };
	int iIndex = 0;
	for (int i = -1; i <= 1; ++i)
	{
		for (int j = -1; j <= 1; ++j)
		{
			int iNR = iWR + i;
			int iNC = iWC + j;
			if (iNR <= 0 || iNR > iN || iNC <= 0 || iNC > iN)
			{
				IsBlocked[iIndex] = true;
			}
			++iIndex;
		}
	}
	while (iK--)
	{
		int iBR, iBC;
		cin >> iBR >> iBC;
		int iIndex = 0;
		for (int i = -1; i <= 1; ++i)
		{
			for (int j = -1; j <= 1; ++j)
			{
				int iNR = iWR + i;
				int iNC = iWC + j;

				int iDiffR = abs(iNR - iBR);
				int iDiffC = abs(iNC - iBC);
				if (iDiffR == 0 || iDiffC == 0 || (iDiffR == iDiffC))
				{
					IsBlocked[iIndex] = true;
				}
				++iIndex;
			}
		}
	}

	int iCountBound = 0;
	for (int i = 0; i < 9; ++i)
	{
		if (i == 4) 
		{
			continue;
		}
		if (IsBlocked[i])
		{
			++iCountBound;
		}
	}
	if (IsBlocked[4])
	{
		if (iCountBound == 8)
		{
			cout << "CHECKMATE" << "\n";
		}
		else
		{
			cout << "CHECK" << "\n";
		}
	}
	else
	{
		if (iCountBound == 8)
		{
			cout << "STALEMATE" << "\n";
		}
		else
		{
			cout << "NONE" << "\n";
		}
	}
	return 0;
}
