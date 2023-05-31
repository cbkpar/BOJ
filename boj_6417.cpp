#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (true)
	{
		int iN;
		cin >> iN;
		if (iN == -1) break;

		int iAns = -1;
		for (int i = iN; i > 1; --i)
		{
			int iTemp = iN;
			int iCount = 0;
			for (int j = 0; j < i; ++j)
			{
				--iTemp;
				if (iTemp < 0 || iTemp % i != 0) break;
				iTemp /= i;
				iTemp *= i - 1;
				++iCount;
			}
			if (iCount == i)
			{
				iAns = i;
				break;
			}
		}
		cout << iN << " coconuts, ";
		if (iAns == -1)
		{
			cout << "no solution\n";
		}
		else
		{
			cout << iAns << " people and 1 monkey\n";
		}
	}
	return 0;
}
