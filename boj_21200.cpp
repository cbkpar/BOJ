#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iP , iS;
	cin >> iN >> iP >> iS;
	while (iS--)
	{
		bool bExist = false;

		int iT;
		cin >> iT;
		while (iT--)
		{
			int iNum;
			cin >> iNum;
			if (iNum == iP) bExist = true;
		}

		if (bExist)
		{
			cout << "KEEP" << "\n";
		}
		else
		{
			cout << "REMOVE" << "\n";
		}
	}

	return 0;
}
