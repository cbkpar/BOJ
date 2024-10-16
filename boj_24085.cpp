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
	vector<int> vecNum(2001, 0);
	for (int i = 0;i < iN;++i)
	{
		int iNum;
		cin >> iNum;
		++vecNum[iNum];
	}

	int iAns = -1;
	int iMax = 999999;
	for (int i = 1;i <= 2000;++i)
	{
		if (vecNum[i] < iMax && vecNum[i] > 0)
		{
			iAns = i;
			iMax = vecNum[i];
		}
	}

	cout << iAns << "\n";
	return 0;
}
