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
	for (int i = 0;i < iN;++i)
	{
		cin >> vecNum[i];
	}

	int iT;
	cin >> iT;

	int iAns = -1;
	int iRest = 9999999;
	for (int i = 0;i < iN;++i)
	{
		if (iT % vecNum[i] < iRest)
		{
			iRest = iT % vecNum[i];
			iAns = vecNum[i];
		}
	}

	cout << iAns << "\n";
	return 0;
}
