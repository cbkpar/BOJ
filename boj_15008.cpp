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
	for (int i = 0; i < iN; ++i)
	{
		cin >> vecNum[i];
	}
	sort(vecNum.begin(), vecNum.end(), greater<>());

	int iSumA = 0;
	int iSumB = 0;
	for (int i = 0; i < iN; ++i)
	{
		if (i % 2 == 0)
		{
			iSumA += vecNum[i];
		}
		else
		{
			iSumB += vecNum[i];
		}
	}
	cout << iSumA << " " << iSumB << "\n";
	return 0;
}
