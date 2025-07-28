#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iK;
	cin >> iN >> iK;

	string strLine;
	cin >> strLine;

	for (int i = 0;i <= iN - iK;++i)
	{
		cout << strLine[(i + (iK - 1)) % iN];
	}
	if ((iN - iK) % 2 == 1 || iK == 1)
	{
		for (int i = iN - iK + 1;i < iN;++i)
		{
			cout << strLine[(i + (iK - 1)) % iN];
		}
	}
	else
	{
		for (int i = iN - iK + 1;i < iN;++i)
		{
			cout << strLine[iK - 1 - (i - (iN - iK))];
		}
	}

	cout << "\n";
	return 0;
}
