#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long lN, lK, lX, lY;
	cin >> lN >> lK >> lX >> lY;

	long long lBlock = lN / lK * lX + (lN - lN / lK) * lY;
	long long lBlock2 = (lK - 1) * lY + lX;

	int iT;
	cin >> iT;
	while (iT--)
	{
		long long lLevel;
		cin >> lLevel;

		if (lLevel > lBlock)
		{
			lLevel = (lLevel - 1) % lBlock + 1;
		}

		long long lAns = 0;
		if (lLevel > lBlock2)
		{
			lAns += lK * ((lLevel - 1) / lBlock2);
			lLevel = (lLevel - 1) % lBlock2 + 1;
		}
		if (lLevel <= (lK - 1) * lY)
		{
			lAns += (lLevel + lY - 1) / lY;
		}
		else
		{
			lAns += lK;
		}
		cout << lAns << "\n";
	}
	return 0;
}
