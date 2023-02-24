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

	int iT;
	cin >> iT;
	while (iT--)
	{
		int iN;
		cin >> iN;
		cout << "1";
		for (int i = 2; i < iN; ++i)
		{
			if (1 == gcd(i, iN))
			{
				cout << " " << i;
			}
		}
		cout << "\n";
	}

	return 0;
}
