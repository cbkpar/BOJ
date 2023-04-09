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
	vector<int> vecWidth(iN);
	vector<int> vecMin(iN);
	for (int i = 0; i < iN; ++i) cin >> vecWidth[i];
	vecMin[0] = vecWidth[0];
	for (int i = 1; i < iN; ++i)
	{
		vecMin[i] = min(vecMin[i - 1], vecWidth[i]);
	}
	int iAns = iN;
	while (iM--)
	{
		int iWidth;
		cin >> iWidth;
		--iAns;

		while (iAns >= 0 && vecMin[iAns] < iWidth)
		{
			--iAns;
		}
	}
	if (iAns < 0)
	{
		cout << "0\n";
	}
	else
	{
		cout  << (iAns + 1) << "\n";
	}
	return 0;
}
