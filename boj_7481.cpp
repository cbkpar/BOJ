#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;
	while (iN--)
	{
		int iA, iB, iS;
		cin >> iA >> iB >> iS;

		int iMax = 1000000001;
		int iCountA = 0;
		int iCountB = 0;
		int iMaxCount = iA > iB ? iA : iB;

		for (int i = 0; i <= iMaxCount; ++i)
		{
			int iRest = iS - iB * i;
			if (iRest >= 0 && (iRest % iA == 0))
			{
				if ((iRest / iA) + i < iMax)
				{
					iCountA = iRest / iA;
					iCountB = i;
					iMax = iCountA + iCountB;
				}
			}
			iRest = iS - iA * i;
			if (iRest >= 0 && (iRest % iB == 0))
			{
				if ((iRest / iB) + i < iMax)
				{
					iCountA = i;
					iCountB = iRest / iB;
					iMax = iCountA + iCountB;
				}
			}
		}
		if (iMax == 1000000001)
		{
			cout << "Impossible\n";
		}
		else
		{
			cout << iCountA << " " << iCountB << "\n";
		}

	}

	return 0;
}
