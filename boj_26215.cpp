#include <iostream>
#include <algorithm>

using namespace std;

int ArrHeight[100];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;
	for (int i = 0; i < iN; ++i)
	{
		cin >> ArrHeight[i];
	}

	int iCount = 0;
	while (true)
	{
		if (iCount > 1440)
		{
			break;
		}
		sort(ArrHeight, ArrHeight + iN);
		if (ArrHeight[iN - 1] == 0)
		{
			break;
		}
		if (ArrHeight[iN - 2] != 0)
		{
			iCount += ArrHeight[iN - 2];
			ArrHeight[iN - 1] -= ArrHeight[iN - 2];
			ArrHeight[iN - 2] = 0;
		}
		else
		{
			iCount += ArrHeight[iN - 1];
			ArrHeight[iN - 1] = 0;
		}

	}
	if (iCount <= 1440)
	{
		cout << iCount << "\n";
	}
	else
	{
		cout << "-1\n";
	}
	return 0;
}
