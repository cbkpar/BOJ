#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iQ;
	cin >> iN >> iQ;
	vector<int> vecNum(iN, 0);
	for (int i = 0; i < iN; ++i) cin >> vecNum[i];

	int iOffset = 0;
	while (iQ--)
	{
		int iCommand;
		cin >> iCommand;
		if (iCommand == 1)
		{
			int iPos, iSum;
			cin >> iPos >> iSum;
			iPos = (iPos - 1 + iOffset) % iN;
			vecNum[iPos] += iSum;
		}
		else if (iCommand == 2)
		{
			int iAmount;
			cin >> iAmount;
			iAmount %= iN;
			iOffset = (iOffset - iAmount + iN) % iN;
		}
		else if (iCommand == 3)
		{
			int iAmount;
			cin >> iAmount;
			iAmount %= iN;
			iOffset = (iOffset + iAmount) % iN;
		}
	}
	for (int i = 0; i < iN; ++i)
	{
		cout << vecNum[(i + iOffset) % iN] << (i == iN - 1 ? "\n" : " ");
	}
	return 0;
}
