#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	int iN, iM;
	cin >> iN >> iM;

	vector<int> vecP(iN + 1, 0);
	vector<int> vecM(iN + 1, 0);

	while (iM--)
	{
		int iNum, iAbility;
		string strType;
		cin >> iNum >> strType >> iAbility;

		if (strType == "P")
		{
			vecP[iNum] = iAbility + 1;
		}
		else
		{
			vecM[iNum] = iAbility + 1;
		}
	}

	int iMin = 0;
	int iMax = 0;
	for (int i = 1;i <= iN;++i)
	{
		if (vecP[i] == 2 && vecM[i] == 1)
		{
			++iMin;
		}
		if (vecP[i] != 1 && vecM[i] != 2)
		{
			++iMax;
		}
	}

	cout << iMin << " " << iMax << "\n";
	return 0;
}
