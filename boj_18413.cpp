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

	vector<int> vecNum(iN, 0);
	for (int i = 0;i < iN;++i)
	{
		cin >> vecNum[i];
	}

	int iAns = 0;
	for (int i = 1;i <= iM;++i)
	{
		int iTemp = 0;
		for (int j = 0;j < iN;++j)
		{
			if (vecNum[j] == i)
			{
				++iTemp;
			}
		}
		iAns = max(iAns, iTemp);
	}

	cout << iAns << "\n";
	return 0;
}
