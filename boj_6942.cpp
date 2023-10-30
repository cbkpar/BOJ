#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int ConvertNum(int iNum)
{
	int iRet = 0;
	while (iNum)
	{
		int iTemp = iNum % 10;
		iRet *= 10;
		switch (iTemp)
		{
		case 0:
			iRet += 0;
			break;
		case 1:
			iRet += 1;
			break;
		case 6:
			iRet += 9;
			break;
		case 8:
			iRet += 8;
			break;
		case 9:
			iRet += 6;
			break;
		default:
			return -1;
		}
		iNum /= 10;
	}
	return iRet;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iM;
	cin >> iN >> iM;

	int iAns = 0;
	for (int i = iN; i <= iM; ++i)
	{
		if (ConvertNum(i) == i)
		{
			++iAns;
		}
	}

	cout << iAns << "\n";
	return 0;
}
