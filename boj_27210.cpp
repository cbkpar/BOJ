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

	vector<int> vecNum(iN + 1, 0);
	for (int i = 1; i <= iN; ++i) cin >> vecNum[i];

	vector<int> dpLeft(iN + 1, 0);
	vector<int> dpRight(iN + 1, 0);

	for (int i = 1; i <= iN; ++i)
	{
		dpLeft[i] = dpLeft[i - 1];
		dpRight[i] = dpRight[i - 1];
		if (vecNum[i] == 1)
		{
			++dpLeft[i];
			if (--dpRight[i] < 0) dpRight[i] = 0;
		}
		else
		{
			if (--dpLeft[i] < 0) dpLeft[i] = 0;
			++dpRight[i];
		}
	}
	int iAns = 0;
	for (int i = 1; i <= iN; ++i)
	{
		iAns = max(iAns, dpLeft[i]);
		iAns = max(iAns, dpRight[i]);
	}
	cout << iAns << "\n";
	return 0;
}
