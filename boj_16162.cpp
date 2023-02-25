#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iA, iD;
	cin >> iN >> iA >> iD;

	int iCount = 0;
	for (int i = 0; i < iN; ++i)
	{
		int iHeight;
		cin >> iHeight;
		if (iHeight == iA + iCount * iD) ++iCount;
	}
	cout << iCount << "\n";

	return 0;
}
