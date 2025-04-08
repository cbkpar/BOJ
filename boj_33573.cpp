#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

long long NumReverse(long long lNum)
{
	long long lTemp = 0;
	while (lNum > 0)
	{
		lTemp *= 10;
		lTemp += lNum % 10;
		lNum /= 10;
	}
	return lTemp;
}


bool IsSquare(long long lNum)
{
	long long lTemp = sqrt(lNum);
	return lTemp * lTemp == lNum;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iT;
	cin >> iT;
	while (iT-- > 0)
	{
		long long lNum;
		cin >> lNum;

		bool bSquareA = IsSquare(lNum);
		bool bSquareB = IsSquare(NumReverse(lNum));

		if (bSquareA && bSquareB)
		{
			cout << "YES" << "\n";
		}
		else
		{
			cout << "NO" << "\n";
		}
	}

	return 0;
}
