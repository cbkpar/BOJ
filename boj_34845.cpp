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

	int iN;
	cin >> iN;

	int iX;
	cin >> iX;

	int iSum = 0;
	for (int i = 0; i < iN; ++i)
	{
		int iScore;
		cin >> iScore;
		iSum += iScore;
	}

	int iAns = 0;
	int iCount = iN;
	if (iSum < iX * iN)
	{
		iAns = (iX * iN - iSum + 99 - iX) / (100 - iX);
	}
	cout << iAns << "\n";
	return 0;
}
