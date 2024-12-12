#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iMax = -1;
	int iMin = 10000;

	int iN;
	cin >> iN;
	while(iN-- > 0)
	{
		int iLow, iHigh;
		cin >> iLow >> iHigh;

		iMax = max(iMax, iLow);
		iMin = min(iMin, iHigh);
	}

	if(iMax <= iMin)
	{
		cout << "gunilla has a point" << "\n";
	}
	else
	{
		cout << "edward is right" << "\n";
	}

	return 0;
}
