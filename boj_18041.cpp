#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iX;
	cin >> iN >> iX;

	vector<int> vecNum(iN + 1, 0);
	for (int i = 1;i <= iN;++i)
	{
		cin >> vecNum[i];
	}

	int iAns = 0;

	int iNow = 0;
	for (int i = 1;i <= iN;++i)
	{
		if (vecNum[i] - vecNum[i - 1] <= iX)
		{
			++iNow;
		}
		else
		{
			iNow = 1;
		}
		iAns = max(iAns, iNow);
	}

	cout << iAns << "\n";
	return 0;
}
