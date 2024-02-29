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

	vector<long long> vecNum(iN, 0);
	long long lSum = 0;
	for (int i = 0;i < iN;++i)
	{
		cin >> vecNum[i];
		lSum += vecNum[i];
	}

	int iIndex = -1;
	for (int i = 0;i < iN;++i)
	{
		if (lSum == vecNum[i] * 2)
		{
			iIndex = i;
		}
	}

	for (int i = 0;i < iN;++i)
	{
		if (i == iIndex) continue;
		cout << vecNum[i] << " ";
	}
	cout << vecNum[iIndex] << "\n";
	return 0;
}
