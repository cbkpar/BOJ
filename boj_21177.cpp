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
	for (int i = 0; i < iN; ++i)
	{
		cin >> vecNum[i];
	}

	sort(vecNum.begin(), vecNum.end());
	
	long long lSum = vecNum[0];
	for (int i = 1; i < iN; ++i)
	{
		if (vecNum[i] != vecNum[i - 1] + 1)
		{
			lSum += vecNum[i];
		}
	}
	cout << lSum << "\n";
	return 0;
}
