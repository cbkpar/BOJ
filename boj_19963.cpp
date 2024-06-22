#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int iN, iM, iK;
	cin >> iN >> iM >> iK;

	vector<bool> vecUse(iN + 1, false);
	for (int i = 0; i < iM; ++i)
	{
		int iNum;
		cin >> iNum;
		vecUse[iNum] = true;
	}
	for (int i = 0; i < iK; ++i)
	{
		int iNum;
		cin >> iNum;
		vecUse[iNum] = true;
	}

	int iCount = iN - iM - iK;
	cout << iCount << "\n";
	for (int i = 1; i <= iN; ++i)
	{
		if (!vecUse[i])
		{
			cout << i << ((--iCount == 0 ? "\n" : " "));
		}
	}
	return 0;
}
