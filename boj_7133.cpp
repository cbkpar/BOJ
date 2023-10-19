#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> vecDM(2, 0);
	vector<int> vecDH(2, 0);

	cin >> vecDM[0] >> vecDM[1];
	cin >> vecDH[0] >> vecDH[1];

	int iAns = 0;

	int iN;
	cin >> iN;
	while (iN--)
	{
		int iSum = 0;
		int iA, iB;
		cin >> iA >> iB;

		int iSumA = 0;
		int iSumB = 0;

		for (int i = 0; i < iA; ++i)
		{
			if (vecDM[0] - vecDM[1] * i > 0)
			{
				iSumA += vecDM[0] - vecDM[1] * i;
			}
		}
		for (int i = 0; i < iB; ++i)
		{
			if (vecDH[0] - vecDH[1] * i > 0)
			{
				iSumB += vecDH[0] - vecDH[1] * i;
			}
		}
		iAns += max(iSumA, iSumB);
	}

	cout << iAns << "\n";
	return 0;
}
