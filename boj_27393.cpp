#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iA, iB, iC;
	cin >> iA >> iB >> iC;

	int iAns = iA + iB + iC;
	for (int i = 0; i < 4; ++i)
	{
		int iTemp = 0;
		if (i == 0) iTemp = iA + iB;
		if (i == 1) iTemp = iA - iB;
		if (i == 2) iTemp = iA * iB;
		if (i == 3)
		{
			if (iA % iB != 0) continue;
			iTemp = iA / iB;
		}
		for (int j = 0; j < 4; ++j)
		{
			int iTemp2 = 0;
			if (j == 0) iTemp2 = iTemp + iC;
			if (j == 1) iTemp2 = iTemp - iC;
			if (j == 2) iTemp2 = iTemp * iC;
			if (j == 3)
			{
				if (iTemp % iC != 0) continue;
				iTemp2 = iTemp / iC;
			}
			if (iTemp2 >= 0)
			{
				iAns = min(iAns, iTemp2);
			}
		}
	}
	cout << iAns << "\n";
	return 0;
}
