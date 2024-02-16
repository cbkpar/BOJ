#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iSum = 0;
	bool bGold = true;

	int iN;
	cin >> iN;

	while (iN--)
	{
		int iGet, iLost;
		cin >> iGet >> iLost;
		int iScore = iGet * 5 - iLost * 3;
		if (iScore > 40)
		{
			++iSum;
		}
		else
		{
			bGold = false;
		}
	}

	cout << iSum << (bGold ? "+" : "") << "\n";
	return 0;
}
