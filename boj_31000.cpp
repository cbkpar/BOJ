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

	int iAns = (2 * iN + 1) * (2 * iN + 1);
	for (int i = -iN;i <= iN;++i)
	{
		if (i == 0) continue;

		for (int j = -iN;j <= iN;++j)
		{
			int iNum = 1 - i - j;
			if (iNum >= -iN && iNum <= iN) ++iAns;
		}
	}

	cout << iAns << "\n";
	return 0;
}
