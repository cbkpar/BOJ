#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iSx, iSy;
	cin >> iSx >> iSy;

	int iEx, iEy;
	cin >> iEx >> iEy;

	int iPx, iPy;
	cin >> iPx >> iPy;

	if (iSx != iEx && iSy != iEy)
	{
		cout << "1" << "\n";
	}
	else
	{
		if (iSx == iEx)
		{
			if (iSx == iPx && iSy <= iPy && iPy <= iEy)
			{
				cout << "2" << "\n";
			}
			else if (iSx == iPx && iSy >= iPy && iPy >= iEy)
			{
				cout << "2" << "\n";
			}
			else
			{
				cout << "0" << "\n";
			}
		}
		else
		{
			if (iSy == iPy && iSx <= iPx && iPx <= iEx)
			{
				cout << "2" << "\n";
			}
			else if (iSy == iPy && iSx >= iPx && iPx >= iEx)
			{
				cout << "2" << "\n";
			}
			else
			{
				cout << "0" << "\n";
			}
		}
	}
	return 0;
}
