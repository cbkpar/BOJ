#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int iA, int iB)
{
	if (iB % iA == 0) return iA;
	return gcd(iB % iA, iA);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;
	for (int i = iN - 1; i >= 2; --i)
	{
		if (gcd(i, iN) == 1)
		{
			bool bPossible = true;
			for (int j = 2; j * j <= i; ++j)
			{
				if (i % (j * j) == 0)
				{
					bPossible = false;
					break;
				}
			}
			if (bPossible)
			{
				cout << i << "\n";
				return 0;
			}
		}
	}

	return 0;
}
