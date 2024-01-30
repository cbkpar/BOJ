#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t = 0;
	while (true)
	{
		int iN;
		cin >> iN;
		if (iN == 0) break;
		++t;

		int iDTemp, iPTemp;
		iDTemp = 1;
		iPTemp = 1000000;

		for (int i = 0;i < iN;++i)
		{
			int iD, iP;
			cin >> iD >> iP;
			if (iP * (iDTemp * iDTemp) < iPTemp * (iD * iD))
			{
				iDTemp = iD;
				iPTemp = iP;
			}
		}
		cout << "Menu " << t << ": " << iDTemp << "\n";
	}
	return 0;
}
