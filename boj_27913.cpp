#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iQ;
	cin >> iN >> iQ;

	vector<bool> vecBig(iN + 1, false);
	for (int i = 1;i <= iN;++i)
	{
		if (i % 10 == 1) vecBig[i] = true;
		if (i % 10 == 4) vecBig[i] = true;
		if (i % 10 == 7) vecBig[i] = true;
	}

	int iAns = 0;
	for (int i = 1;i <= iN;++i)
	{
		if (vecBig[i])
		{
			++iAns;
		}
	}

	while (iQ-- > 0)
	{
		int iX;
		cin >> iX;
		if (vecBig[iX])
		{
			--iAns;
		}
		else
		{
			++iAns;
		}
		vecBig[iX] = !vecBig[iX];
		cout << iAns << "\n";
	}
	return 0;
}
