#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> vecScore(80001, 0);
	vecScore[0] = 10;
	for (int i = 1; i <= 40000; ++i)
	{
		int iSqrt = (int)sqrt(i - 1);
		vecScore[i] = 10 - iSqrt / 20;
	}

	int iT;
	cin >> iT;
	while (iT--)
	{
		int iN;
		cin >> iN;

		int iSum = 0;
		while (iN--)
		{
			int iX, iY;
			cin >> iX >> iY;
			int iR = iX * iX + iY * iY;
			iSum += vecScore[iR];
		}
		cout << iSum << "\n";
	}

	return 0;
}
