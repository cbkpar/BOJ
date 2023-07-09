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

	int iN;
	cin >> iN;

	int iSqrt = (int)sqrt(iN);
	for (int i = 1; i <= iSqrt; ++i)
	{
		if (iN % i == 0)
		{
			int iA = i;
			int iC = iN / i;

			int iSqrt2 = (int)sqrt(iN+2);
			for (int j = 1; j <= iSqrt2; ++j)
			{
				if ((iN + 2) % j == 0)
				{
					int iB = j;
					int iD = (iN + 2) / j;

					if (iA * iD - iB * iC == iN + 1)
					{
						cout << iA << " " << (-iB) << " " << iC << " " << iD << "\n";
						return 0;
					}
					if (- iA * iD + iB * iC == iN + 1)
					{
						cout << iA << " " << iB << " " << iC << " " << (-iD) << "\n";
						return 0;
					}
					if (iA * iB - iD * iC == iN + 1)
					{
						cout << iA << " " << (-iD) << " " << iC << " " << iB << "\n";
						return 0;
					}
					if (-iA * iB + iD * iC == iN + 1)
					{
						cout << iA << " " << iD << " " << iC << " " << (-iB) << "\n";
						return 0;
					}
				}
			}
		}
	}
	cout << "-1\n";
	return 0;
}
