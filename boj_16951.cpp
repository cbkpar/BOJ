#include <iostream>

using namespace std;

int arrHeight[1000] = { 0, };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iK;
	cin >> iN >> iK;
	for (int i = 0; i < iN; ++i)
	{
		cin >> arrHeight[i];
	}

	int iAns = iN;
	for (int i = 1; i <= 1000; ++i)
	{
		int iCount = 0;
		for (int j = 0; j < iN; ++j)
		{
			if (arrHeight[j] != j * iK + i)
			{
				++iCount;
			}
		}
		if (iCount < iAns)
		{
			iAns = iCount;
		}
	}
	cout << iAns << "\n";

	return 0;
}
