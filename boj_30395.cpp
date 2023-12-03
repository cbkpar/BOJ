#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;

	int iNow = 0;
	int iMax = 0;

	int iUsed = -2;
	for (int i = 0; i < iN; ++i)
	{
		int iSolve;
		cin >> iSolve;

		if (iSolve > 0)
		{
			++iNow;
		}
		else
		{
			if (i >= iUsed + 2)
			{
				iUsed = i;
			}
			else
			{
				iNow = 0;
			}
		}
		iMax = max(iMax, iNow);
	}

	cout << iMax << "\n";
	return 0;
}
