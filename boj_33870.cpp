#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iM;
	cin >> iN >> iM;

	vector<int> vecDog(iN + 1, 0);
	for (int i = 1;i <= iN;++i)
	{
		cin >> vecDog[i];
	}

	vector<int> vecBrush(iM, 0);
	for (int i = 0;i < iM;++i)
	{
		cin >> vecBrush[i];
	}

	int iAns = 0;
	for (int i = 1;i <= iN;++i)
	{
		int iNow = 0;
		for (int j = 0;j < iM;++j)
		{
			++iNow;
			if (vecBrush[j] != i) continue;
			if (iNow <= vecDog[i])
			{
				iNow = 0;
			}
			if (j > 0 && vecBrush[j-1] == i)
			{
				iNow = 0;
			}
		}
		if (iNow >= vecDog[i])
		{
			++iAns;
		}
	}
	cout << iAns << "\n";
	return 0;
}
