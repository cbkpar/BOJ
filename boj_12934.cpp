#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long lX, lY;
	cin >> lX >> lY;

	long long lSum = lX + lY;
	long long lSqrt = (long long)sqrt(lSum * 2);

	if (lSqrt * (lSqrt + 1) / 2 != lSum)
	{
		cout << "-1\n";
		return 0;
	}

	int iCount = 0;
	for (long long i = lSqrt; i >= 1; --i)
	{
		if (lX >= i)
		{
			lX -= i;
			++iCount;
		}
	}
	cout << iCount << "\n";
	return 0;
}
