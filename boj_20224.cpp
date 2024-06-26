#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (true)
	{
		int iN;
		cin >> iN;

		if (iN == 0) break;

		vector<int> vecNum(iN, 0);
		for (int i = 0;i < iN;++i)
		{
			cin >> vecNum[i];
		}
		int iAns = 0;
		for (int i = 3;i < iN;++i)
		{
			if (vecNum[i - 3] == 2 && vecNum[i - 2] == 0 && vecNum[i - 1] == 2 && vecNum[i] == 0)
			{
				++iAns;
			}
		}
		cout << iAns << "\n";
	}

	return 0;
}
