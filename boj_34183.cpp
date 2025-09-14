#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iM, iA, iB;
	cin >> iN >> iM >> iA >> iB;

	if (iN * 3 <= iM)
	{
		cout << "0" << "\n";
	}
	else
	{
		int iCost = (iN * 3 - iM) * iA + iB;
		cout << iCost << "\n";
	}

	return 0;
}
