#include <iostream>

using namespace std;

long dp[101] = { 0, };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iM;
	cin >> iM;
	int iLeft = 1;
	int iRight = 1000000001;
	int iAns = 2147483647;
	while (iLeft <= iRight)
	{
		int iMid = (iLeft + iRight) / 2;
		int iTemp = iMid;
		int iSum = 0;
		while (iTemp)
		{
			iSum += iTemp / 5;
			iTemp /= 5;
		}
		if (iSum >= iM)
		{
			if (iSum == iM && iMid < iAns)
			{
				iAns = iMid;
			}
			iRight = iMid - 1;
		}
		else
		{
			iLeft = iMid + 1;
		}
	}
	if (iAns == 2147483647)
	{
		cout << "-1\n";
	}
	else
	{
		cout << iAns << "\n";
	}
	return 0;
}
