#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

bool PrimeCheck(int iNum)
{
	if (iNum < 2) return false;
	int iSqrt = (int)sqrt(iNum);
	for (int i = 2; i <= iSqrt; ++i)
	{
		if (iNum % i == 0) return false;
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	bool ArrPrime[50001] = { false, };
	for (int i = 2; i * i <= 50000; i++) {
		for (int j = i * i; j <= 50000; j += i) {
			ArrPrime[j] = true;
		}
	}

	int iN;
	cin >> iN;

	for (int i = 2; i <= 50000; ++i)
	{
		if (!ArrPrime[i])
		{
			if (iN % i == 0)
			{
				int iTemp = iN;
				while (iTemp % i == 0)
				{
					iTemp /= i;
				}
				if (iTemp == 1)
				{
					cout << "yes" << "\n";
					return 0;
				}
			}
		}
	}
	
	if (PrimeCheck(iN) == true)
	{
		cout << "yes" << "\n";
	}
	else
	{
		cout << "no" << "\n";
	}

	return 0;
}
