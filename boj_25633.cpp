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

	vector<int> vecHeight(iN, 0);
	for (int i = 0;i < iN;++i)
	{
		cin >> vecHeight[i];
	}

	int iAns = 0;
	for (int i = 0;i < iN;++i)
	{
		int iCount = 1;
		int iSum = vecHeight[i];
		for (int j = i + 1;j < iN;++j)
		{
			if (vecHeight[j] <= iSum)
			{
				iSum += vecHeight[j];
				++iCount;
			}
		}
		iAns = max(iAns, iCount);
	}

	cout << iAns << "\n";
	return 0;
}
