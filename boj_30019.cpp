#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iM;
	cin >> iN >> iM;

	vector<int> vecTime(iN + 1, 0);

	while (iM--)
	{
		int iRoom, iS, iE;
		cin >> iRoom >> iS >> iE;

		if (vecTime[iRoom] < iS)
		{
			vecTime[iRoom] = iE - 1;
			cout << "YES" << "\n";
		}
		else
		{
			cout << "NO" << "\n";
		}
	}
	return 0;
}
