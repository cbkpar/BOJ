#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iK, iP;
	cin >> iN >> iK >> iP;

	int iAns = 0;
	for (int i = 0; i < iN; ++i)
	{
		int iCount = 0;
		for (int j = 0; j < iK; ++j)
		{
			int iCream;
			cin >> iCream;
			if (iCream == 0)
			{
				++iCount;
			}
		}
		if (iCount < iP)
		{
			++iAns;
		}
	}
	cout << iAns << "\n";
	return 0;
}
