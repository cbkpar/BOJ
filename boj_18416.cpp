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

	vector<int> vecNum(iN, 0);
	for (int i = 0;i < iN;++i) cin >> vecNum[i];

	int iAns = 1;
	for (int i = 0;i < iN;++i)
	{
		int iTemp = 1;
		for (int j = i + 1;j < iN;++j)
		{
			if (vecNum[j] < vecNum[j - 1]) break;
			++iTemp;
		}
		iAns = max(iAns, iTemp);
	}

	cout << iAns << "\n";
	return 0;
}
