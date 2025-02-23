#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;

	int iT;
	cin >> iT;

	vector<int> vecNum(iN * 2, 0);
	for (int i = 0; i < 2 * iN; ++i)
	{
		cin >> vecNum[i];
	}

	int iNow = 0;
	for (int i = 0; i < iT; ++i)
	{
		int iNum;
		cin >> iNum;
		iNow = (iNow + iNum - 1) % (2 * iN);
		cout << vecNum[iNow] << (i == iT - 1 ? "\n" : " ");
	}

	return 0;
}
