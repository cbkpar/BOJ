#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iL, iC;
	cin >> iN >> iL >> iC;

	int iAmount = (iC + 1) / (iL + 1);
	if (iAmount % 13 == 0) --iAmount;

	int iAns = 0;
	while (iN > 0)
	{
		if (iN >= iAmount)
		{
			iN -= iAmount;
			++iAns;
		}
		else
		{
			if (iN % 13 == 0)
			{
				int iDiff = iAmount - (iAmount + iN + 1) / 2;
				if ((iAmount - iDiff) % 13 == 0) --iDiff;

				if (iAns == 0 || iDiff == 0) ++iAns;
				++iAns;
			}
			else
			{
				++iAns;
			}
			iN = 0;
		}
	}

	cout << iAns << "\n";
	return 0;
}
