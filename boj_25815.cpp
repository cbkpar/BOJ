#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iY, iM;
	cin >> iY >> iM;

	int iAns = 0;
	if(iY < 1)
	{
		iAns += iM * 15;
	}
	else if (iY == 1)
	{
		iAns = 15;
		iAns *= 12;
		iAns += iM * 9;
	}
	else
	{
		iAns = 24 + (iY-2) * 4;
		iAns *= 12;
		iAns += iM * 4;
	}

	cout << (iAns / 12) << " " << (iAns % 12) << "\n";
	return 0;
}
