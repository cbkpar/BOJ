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

	int iSum = 0;
	int iAns = 0;

	vector<int> vecNum(iN, 0);
	for (int i = 0; i < iN; ++i)
	{
		cin >> vecNum[i];
	}
	for (int i = 1; i < iN; ++i)
	{
		if (vecNum[i] > vecNum[i - 1])
		{
			iSum += vecNum[i] - vecNum[i - 1];
		}
		else
		{
			iSum = 0;
		}
		iAns = max(iAns, iSum);
	}

	cout << iAns << "\n";
	return 0;
}
