#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long Calc(long long lNum)
{
	long long lA = 4;
	long long lB = 9;
	while (true)
	{
		if (lNum <= lA)
		{
			return lNum * (lB - lNum);
		}
		if (lNum <= lB)
		{
			return lA * (lA + 1);
		}
		lA = lA * 10 + 9;
		lB = lB * 10 + 9;
	}
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iT;
	cin >> iT;
	while (iT--)
	{
		long long lNum;
		cin >> lNum;
		cout << Calc(lNum) << "\n";
	}
	return 0;
}
