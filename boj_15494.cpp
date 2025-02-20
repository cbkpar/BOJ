#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;

	int iMaxA = -1;
	int iMinB = 99999999;

	for (int i = 100;i > 0;--i)
	{
		if ((iN - 364 * i) % 1092 == 0 && (iN - 364 * i) > 0)
		{
			iMaxA = max(iMaxA, i);
			iMinB = min(iMinB, ((iN - 364 * i) / 1092));
		}
	}

	cout << iMaxA << "\n";
	cout << iMinB << "\n";

	return 0;
}
