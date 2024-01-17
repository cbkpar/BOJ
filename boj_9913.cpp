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

	vector<int> vecNum(1001, 0);
	while (iN--)
	{
		int iNum;
		cin >> iNum;
		++vecNum[iNum];
	}

	int iAns = 0;
	for (int i = 1;i <= 1000;++i)
	{
		iAns = max(iAns, vecNum[i]);
	}
	cout << iAns << "\n";
	return 0;
}
