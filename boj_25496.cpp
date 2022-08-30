#include <iostream>
#include <memory.h>

using namespace std;

int main()
{
	int iN, iM;
	cin >> iN >> iM;
	int* arrCount = new int[201];
	memset(arrCount, 0, sizeof(int) * 201);
	for (int i = 0; i < iM; ++i)
	{
		int iNumber;
		cin >> iNumber;
		++arrCount[iNumber];
	}
	int iCount = 0;
	int iAccCost = iN;
	for (int i = 1; i <= 200; ++i)
	{
		if (iAccCost >= 200)
		{
			break;
		}
		while (arrCount[i]--)
		{
			++iCount;
			iAccCost += i;
			if (iAccCost >= 200)
			{
				break;
			}
		}
	}
	cout << iCount << endl;
	delete[] arrCount;
	return 0;
}
