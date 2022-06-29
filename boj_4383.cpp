#include <iostream>
#include <string.h>

using namespace std;

bool bCheck[3001];

int main()
{
	while (true)
	{
		int iN;
		cin >> iN;
		if (cin.eof())
		{
			break;
		}
		memset(bCheck, false, sizeof(bool) * 3001);
		int iPreNum;
		cin >> iPreNum;
		int iCount = 0;
		for (int i = 1; i < iN; ++i)
		{
			int iNextNum;
			cin >> iNextNum;
			int iDiff = abs(iNextNum - iPreNum);
			if (0 < iDiff && iDiff < iN)
			{
				if (!bCheck[iDiff])
				{
					bCheck[iDiff] = true;
					++iCount;
				}
			}
			iPreNum = iNextNum;
		}
		cout << ((iCount == iN - 1) ? "Jolly" : "Not jolly") << endl;
	}
	return 0;
}
