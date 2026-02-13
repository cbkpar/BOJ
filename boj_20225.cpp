#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (true)
	{
		int iM, iN, iP;
		cin >> iM >> iN >> iP;

		if (iM == 0 && iN == 0 && iP == 0) break;

		vector<bool> vecInf(iM + 1, false);
		vecInf[iP] = true;

		for (int i = 0; i < iN; ++i)
		{
			int iS, iE;
			cin >> iS >> iE;

			if (vecInf[iS] || vecInf[iE])
			{
				vecInf[iS] = true;
				vecInf[iE] = true;
			}
		}

		int iAns = 0;
		for (int i = 1; i <= iM; ++i)
		{
			if (vecInf[i])
			{
				++iAns;
			}
		}
		cout << iAns << "\n";
	}
	return 0;
}
