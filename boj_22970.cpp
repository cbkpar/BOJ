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

	vector<int> vecLeft(iN, 1);
	vector<int> vecRight(iN, 1);

	for (int i = 1; i < iN; ++i)
	{
		if (vecNum[i] > vecNum[i - 1])
		{
			vecLeft[i] = vecLeft[i - 1] + 1;
		}
	}
	for (int i = iN - 2; i >= 0; --i)
	{
		if (vecNum[i] > vecNum[i + 1])
		{
			vecRight[i] = vecRight[i + 1] + 1;
		}
	}
	int iAns = 1;
	for (int i = 0; i < iN; ++i)
	{
		iAns = max(iAns, vecLeft[i] + vecRight[i] - 1);
	}
	cout << iAns << "\n";
	return 0;
}
