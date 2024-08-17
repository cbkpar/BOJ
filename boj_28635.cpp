#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iM, iA, iB;
	cin >> iM >> iA >> iB;

	int iNow = iA;
	int iCount = 0;

	while (true)
	{
		if (iNow == iB) break;
		++iNow;
		++iCount;
		if (iNow > iM) iNow = 1;
	}

	cout << iCount << "\n";
	return 0;
}
