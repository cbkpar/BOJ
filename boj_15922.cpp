#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iAns = 0;
	int iTemp = -1000000001;

	int iN;
	cin >> iN;
	while (iN--)
	{
		int iS, iE;
		cin >> iS >> iE;
		if (iS < iTemp)
		{
			iS = iTemp;
		}
		if (iE > iS)
		{
			iAns += (iE - iS);
			iTemp = iE;
		}
	}
	cout << iAns << "\n";
	return 0;
}
