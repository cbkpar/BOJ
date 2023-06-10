#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iF;
	cin >> iN >> iF;

	int iAns = -1;
	double dMax = 999999999.0;

	for (int i = 1; i <= iN; ++i)
	{
		int iPos, iSpeed;
		cin >> iPos >> iSpeed;
		double dTime = ((double)iF - iPos) / (double)(iSpeed);
		if (dTime < dMax)
		{
			dMax = dTime;
			iAns = i;
		}
	}
	cout << iAns << "\n";
	return 0;
}
