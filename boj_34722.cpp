#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;

	int iAns = 0;
	for (int i = 0; i < iN; ++i)
	{
		int iS, iC, iA, iR;
		cin >> iS >> iC >> iA >> iR;
		bool bPossible = false;
		if (iS >= 1000) bPossible = true;
		if (iC >= 1600) bPossible = true;
		if (iA >= 1500) bPossible = true;
		if (iR > 0 && iR <= 30) bPossible = true;
		if (bPossible) ++iAns;
	}

	cout << iAns << "\n";
	return 0;
}
