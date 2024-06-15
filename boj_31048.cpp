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
		int iN;
		cin >> iN;

		int iAns = 0;
		if (iN == 0) iAns = 1;
		if (iN == 1) iAns = 1;
		if (iN == 2) iAns = 2;
		if (iN == 3) iAns = 6;
		if (iN == 4) iAns = 4;
		cout << iAns << "\n";
	}
	return 0;
}
