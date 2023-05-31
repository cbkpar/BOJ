#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iC;
	cin >> iN >> iC;

	vector<int> vecNum(iN, 0);
	for (int i = 0; i < iN; ++i) cin >> vecNum[i];

	int iAns = 0;
	for (int i = 0; i < iN; ++i)
	{
		int iCount = 0;
		int iTemp = iC;
		for (int j = i; j < iN; ++j)
		{
			if (iTemp >= vecNum[j])
			{
				iTemp -= vecNum[j];
				++iCount;
			}
		}
		iAns = max(iAns, iCount);
	}
	cout << iAns << "\n";
	return 0;
}
