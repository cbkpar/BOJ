#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iW, iH;
	cin >> iW >> iH;

	int iN, iA, iB;
	cin >> iN >> iA >> iB;

	if (iW < iA || iH < iB)
	{
		cout << "-1" << "\n";
		return 0;
	}

	int iCount = (iW / iA) * (iH / iB);
	int iAns = (iN + iCount - 1) / iCount;

	cout << iAns << "\n";
	return 0;
}
