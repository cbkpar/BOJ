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
		for (int i = 0; i < iN; ++i)
		{
			cin >> vecNum[i];
		}
		sort(vecNum.begin(), vecNum.end());

		int iAns = vecNum[1] - vecNum[0];
		for (int i = 2; i < iN; ++i)
		{
			iAns = min(iAns, vecNum[i] - vecNum[i - 1]);
		}
		cout << iAns << "\n";
	}
	
	return 0;
}
