#include <iostream>
#include <memory.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int iX, iY, iM;
	cin >> iX >> iY >> iM;
	bool* arrDP = new bool[iM + 1];
	memset(arrDP, 0, sizeof(bool) * (iM + 1));
	arrDP[0] = true;
	int iAns = 0;
	for (int i = 1; i <= iM; ++i)
	{
		if (i >= iX && arrDP[i-iX])
		{
			arrDP[i] = true;
		}
		if (i >= iY && arrDP[i - iY])
		{
			arrDP[i] = true;
		}
		if (arrDP[i])
		{
			iAns = i;
		}
	}
	cout << iAns << "\n";
	return 0;
}
