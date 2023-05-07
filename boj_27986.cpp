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

	int iMax = iN;

	while (iM--)
	{
		int iL, iR;
		cin >> iL >> iR;
		iMax = min(iMax, iR - iL + 1);
	}
	for (int i = 0; i < iN; ++i)
	{
		cout << ((i % iMax) + 1) << (i == iN - 1 ? "\n" : " ");
	}
	return 0;
}
