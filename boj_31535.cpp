#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iW, iH;
	cin >> iW >> iH;

	int iN, iD;
	cin >> iN >> iD;

	vector<int> vecA(iN + 1, 0);
	for (int i = 1; i <= iN; ++i)
	{
		cin >> vecA[i];
	}

	vector<int> vecP(iN + 1, 0);
	for (int i = 1; i <= iN; ++i)
	{
		cin >> vecP[i];
	}

	vector<int> vecH(iH + 1, 0);
	int iTempIndex = 1;
	for (int i = 1; i <= iH; ++i)
	{
		vecH[i] = vecH[i - 1] + vecP[iTempIndex];
		if (vecA[iTempIndex] == i)
		{
			++iTempIndex;
		}
	}

	int iAns = 1000000000;
	iTempIndex = 1;
	for (int i = 0; i <= iH; ++i)
	{
		if (i != iH && vecA[iTempIndex] == i)
		{
			++iTempIndex;
		}

		int iTempCost = iW * vecP[iTempIndex];

		if (iD < i)
		{
			iTempCost += vecH[iD];
			iTempCost += (vecH[i] - vecH[iD]) * 2;
		}
		else
		{
			iTempCost += vecH[iD];
		}
		iAns = min(iAns, iTempCost);
	}

	cout << iAns << "\n";
	return 0;
}
