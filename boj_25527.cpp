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
		for (int i = 0;i < iN;++i) cin >> vecNum[i];

		int iAns = 0;
		for (int i = 1;i < iN - 1;++i)
		{
			if (vecNum[i] > vecNum[i - 1] && vecNum[i] > vecNum[i + 1])
			{
				++iAns;
			}
		}

		cout << iAns << "\n";
	}
	return 0;
}
