#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (true)
	{
		int iN, iM;
		cin >> iN >> iM;
		if (iN == 0 && iM == 0) break;

		int iAnsA = 1;
		int iAnsB = 9999;

		for (int i = 0; i < iN; ++i)
		{
			int iA, iB;
			cin >> iA >> iB;
			if (iA > iM) continue;

			if (iAnsB * iA > iB * iAnsA)
			{
				iAnsA = iA;
				iAnsB = iB;
			}
			else if (iAnsB * iA == iB * iAnsA)
			{
				if (iA > iAnsA)
				{
					iAnsA = iA;
					iAnsB = iB;
				}
			}
		}

		if (iAnsB == 9999)
		{
			cout << "No suitable tickets offered" << "\n";
		}
		else
		{
			cout << "Buy " << iAnsA << " tickets for $" << iAnsB << "\n";
		}
	}
	return 0;
}
