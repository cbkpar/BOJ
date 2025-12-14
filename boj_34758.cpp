#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iX, iY;
	cin >> iX >> iY;

	int iN;
	cin >> iN;
	for (int i = 0; i < iN; ++i)
	{
		int iTempX, iTempY;
		cin >> iTempX >> iTempY;
		int iAns = 1;
		if (iTempX == iX || iTempY == iY) iAns = 0;
		cout << iAns << "\n";
	}
	return 0;
}
