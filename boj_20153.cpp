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
	vector<int> vecNum(iN);
	for (int i = 0; i < iN; ++i) cin >> vecNum[i];
	int iSum = 0;
	for (int i = 0; i < iN; ++i)
	{
		iSum ^= vecNum[i];
	}

	int iAns = iSum;
	for (int i = 0; i < iN; ++i)
	{
		iAns = max(iAns, iSum ^ vecNum[i]);
	}

	cout << iAns << iAns << "\n";
	return 0;
}
