#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iK, iT;
	cin >> iN >> iK >> iT;

	int iTotal = 0;

	for (int i = 0;i < iN;++i)
	{
		int iTemp;
		cin >> iTemp;

		if (iT < iK)
		{
			iT = iT + iTemp + abs(iT - iK);
		}
		else if (iK < iT)
		{
			iT = iT + iTemp - abs(iT - iK);
		}
		else
		{
			iT = iT + iTemp;
		}


		iTotal += abs(iT - iK);
	}

	cout << iTotal << "\n";
	return 0;
}
