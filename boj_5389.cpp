#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iT;
	cin >> iT;
	while (iT--)
	{
		int iN;
		cin >> iN;

		int iSqrt = (int)sqrt(iN);
		bool bFound = false;
		for (int i = iSqrt; i >= 1; --i)
		{
			if (iN % i == 0)
			{
				int iA = i;
				int iB = iN / i;
				if ((iA + iB) % 2 == 0)
				{
					cout << (iB - iA) / 2 << " " << (iB + iA) / 2 << "\n";
					bFound = true;
					break;
				}
			}
		}
		if (!bFound)
		{
			cout << "IMPOSSIBLE\n";
		}
	}

	return 0;
}
