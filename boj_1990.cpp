#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
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

	int iA, iB;
	cin >> iA >> iB;

	set<int> setAns;

	for (int i = 1; i <= 9999; ++i)
	{
		int iNum = i;
		int iTemp = i;
		while (iTemp)
		{
			iNum *= 10;
			iNum += iTemp % 10;
			iTemp /= 10;
		}
		if (iNum<iA || iNum>iB) continue;
		if (PrimeCheck(iNum))
		{
			setAns.insert(iNum);
		}
	}
	for (int i = 0; i <= 999; ++i)
	{
		for (int j = 0; j <= 9; ++j)
		{
			int iNum = i;
			iNum *= 10;
			iNum += j;
			int iTemp = i;
			while (iTemp)
			{
				iNum *= 10;
				iNum += iTemp % 10;
				iTemp /= 10;
			}
			if (iNum<iA || iNum>iB) continue;
			if (PrimeCheck(iNum))
			{
				setAns.insert(iNum);
			}
		}
	}
	for (auto& iter : setAns)
	{
		cout << (iter) << "\n";
	}

	cout << "-1\n";
	return 0;
}
