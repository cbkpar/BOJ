#include <iostream>
#include <memory.h>

#define Safe_Release_Array(p) if(p){delete[] p;p=nullptr;}

using namespace std;

int main()
{
	int iN;
	cin >> iN;
	long long* arrNumber = new long long[20001];
	memset(arrNumber, 0, sizeof(long long) * 20001);
	for (int i = 0; i < iN; ++i)
	{
		int iNumber;
		cin >> iNumber;
		++arrNumber[iNumber + 10000];
	}
	long long lSum = 0;
	for (int i = 0; i <= 10000; ++i)
	{
		for (int j = i; j <= 20000; ++j)
		{
			int k = 30000 - i - j;
			if (j > k || k > 20001)
			{
				continue;
			}
			if (i == j && j == k)
			{
				if (arrNumber[i] > 2)
				{
					lSum += arrNumber[i] * (arrNumber[j] - 1) * (arrNumber[k] - 2) / 6;
				}
			}
			else if (i == j)
			{
				if (arrNumber[i] > 1)
				{
					lSum += arrNumber[i] * (arrNumber[j] - 1) * arrNumber[k] / 2;
				}
			}
			else if (j == k)
			{
				if (arrNumber[j] > 1)
				{
					lSum += arrNumber[j] * (arrNumber[k] - 1) * arrNumber[i] / 2;
				}
			}
			else
			{
				lSum += arrNumber[i] * arrNumber[j] * arrNumber[k];
			}
		}
	}
	cout << lSum << endl;
	Safe_Release_Array(arrNumber);
	return 0;
}
