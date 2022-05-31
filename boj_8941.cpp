#include <iostream>
#include <string>

using namespace std;

int main()
{
	int iTestCase;
	cin >> iTestCase;
	while (iTestCase--)
	{
		string strName;
		cin >> strName;
		int iLength = strName.length();
		int iAcc = 0;
		int iTemp = 1;
		int iLast = 0;
		for (int i = 0; i < iLength; ++i)
		{
			switch (strName.at(i))
			{
			case 'C':
				iLast = 12010;
				iAcc += iLast;
				iTemp = 0;
				break;
			case 'H':
				iLast = 1008;
				iAcc += iLast;
				iTemp = 0;
				break;
			case 'O':
				iLast = 16000;
				iAcc += iLast;
				iTemp = 0;
				break;
			case 'N':
				iLast = 14010;
				iAcc += iLast;
				iTemp = 0;
				break;
			default:
				iAcc -= iLast * (0 == iTemp ? 1 : iTemp);
				int iN = strName.at(i) - '0';
				iTemp = iTemp * 10 + iN;
				iAcc += iLast * iTemp;
				break;
			}
		}
		printf("%d.%03d\n", iAcc / 1000, iAcc % 1000);
	}
	return 0;
}
