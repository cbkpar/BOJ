#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iAns = 0;

	int iL1, iR1, iL2, iR2, iK;
	cin >> iL1 >> iR1 >> iL2 >> iR2 >> iK;
	for (int i = 1;i <= 50000;++i)
	{
		if (i == iK) continue;
		if (iL1 <= i && i <= iR1 && iL2 <= i && i <= iR2)
		{
			++iAns;
		}
	}

	cout << iAns << "\n";
	return 0;
}
