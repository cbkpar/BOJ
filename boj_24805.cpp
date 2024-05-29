#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iDay = 0;
	int iA, iB, iH;
	cin >> iA >> iB >> iH;

	int iNow = 0;
	while (true)
	{
		++iDay;
		iNow += iA;
		if (iNow >= iH) break;
		iNow -= iB;
	}

	cout << iDay << "\n";
	return 0;
}
