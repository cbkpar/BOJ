#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

long long CalcOrigin(long long lN)
{
	long long lLen = 0;
	long long lTemp = lN;
	while (lTemp)
	{
		++lLen;
		lTemp /= 10;
	}
	long long lAns = 0;
	for (long long lNum = lN; lNum >= lN - lLen * 9; --lNum)
	{
		long long lSum = lNum;
		long long lTemp = lNum;
		while (lTemp)
		{
			lSum += lTemp % 10;
			lTemp /= 10;
		}
		if (lSum == lN)
		{
			lAns = lNum;
		}
	}
	return lAns;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long lN;
	cin >> lN;
	cout << CalcOrigin(lN) << "\n";
	return 0;
}
