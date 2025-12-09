#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iP, iM, iC;
	cin >> iP >> iM >> iC;
	int iX;
	cin >> iX;

	int iAns = 1000000000;
	for (int i = 1;i <= iP;++i)
	{
		for (int j = 1;j <= iM;++j)
		{
			for (int k = 1;k <= iC;++k)
			{
				iAns = min(iAns, abs((i + j) * (j + k) - iX));
			}
		}
	}

	cout << iAns << "\n";
	return 0;
}
