#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iM;
	cin >> iN >> iM;

	vector<int> vecA;
	vector<int> vecB;

	for (int i = 0; i < iN; ++i)
	{
		int iAbility;
		cin >> iAbility;
		if (iAbility * 2 >= iM)
		{
			vecA.push_back(iAbility);
		}
		else
		{
			vecB.push_back(iAbility);
		}
	}

	int iRight = vecA.size() - 1;
	int iAns = 0;
	int iCount = vecA.size();

	sort(vecA.begin(), vecA.end());
	sort(vecB.begin(), vecB.end());

	for (int iNum : vecB)
	{
		while (iRight >= 0 && vecA[iRight] + iNum < iM)
		{
			--iRight;
		}
		if (iRight >= 0 && vecA[iRight] + iNum >= iM)
		{
			--iCount;
			--iRight;
			++iAns;
		}
	}
	iAns += iCount / 2;
	cout << iAns << "\n";
	return 0;
}
