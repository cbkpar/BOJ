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

	int iR = 1;
	int iC = 1;
	int iRMax = 10000;
	int iCMax = 10000;

	for (int i = 1; i <= iN; ++i)
	{
		int iDist;
		cin >> iDist;
		if (iDist < iRMax)
		{
			iRMax = iDist;
			iR = i;
		}
		if (i == iN) iCMax = iDist;
	}
	for (int j = 2; j <= iM; ++j)
	{
		int iDist;
		cin >> iDist;
		if (iDist < iCMax)
		{
			iCMax = iDist;
			iC = j;
		}
	}
	cout << iR << " " << iC << "\n";
	return 0;
}
