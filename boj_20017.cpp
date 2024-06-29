#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iM, iA;
	cin >> iN >> iM >> iA;

	vector<int> vecNum(iN * iM, 0);
	for (int i = 0; i < iN * iM; ++i)
	{
		cin >> vecNum[i];
	}

	int iAns = 0;
	for (int i = 0; i < iN * iM - iM; ++i)
	{
		if (vecNum[i] * 2 < vecNum[i + iM])
		{
			++iAns;
		}
	}

	iAns *= iA;
	cout << iAns << "\n";
	return 0;
}
