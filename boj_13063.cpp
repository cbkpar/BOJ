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
		int iA, iB, iC;
		cin >> iA >> iB >> iC;
		if (iA == 0 && iB == 0 && iC == 0) break;

		int iHalf = (iA + 2) / 2;
		int iNeed = iHalf - iB;
		if (iNeed < 0)
		{
			iNeed = 0;
		}
		if (iNeed > iA - iB - iC)
		{
			cout << "-1" << "\n";
		}
		else
		{
			cout << iNeed << "\n";
		}
	}

	return 0;
}
