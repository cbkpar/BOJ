#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> vecCount(10001, 0);

	int iN;
	cin >> iN;
	while (iN--)
	{
		int iNum;
		cin >> iNum;
		++vecCount[iNum];
	}

	int iAns = -1;
	int iMax = -1;
	for (int i = 1; i <= 10000; ++i)
	{
		if (vecCount[i] > iMax)
		{
			iMax = vecCount[i];
			iAns = i;
		}
	}
	cout << iAns << "\n";
	return 0;
}
