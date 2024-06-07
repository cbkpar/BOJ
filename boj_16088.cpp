#include <iostream>
#include <vector>
#include <algorithm>

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
		int iL, iR, iN, iM;
		cin >> iL >> iR >> iN >> iM;

		int iDiff = abs(iM - iN);

		if (iDiff == 0)
		{
			cout << "G" << "\n";
		}
		else if (iL >= iDiff && iR >= iDiff)
		{
			cout << "E" << "\n";
		}
		else if (iL >= iDiff)
		{
			cout << "L" << "\n";
		}
		else
		{
			cout << "R" << "\n";
		}
	}
	return 0;
}
