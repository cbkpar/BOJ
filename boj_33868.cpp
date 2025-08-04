#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;

	int iMaxT = 0;
	int iMinB = 999999999;

	for (int i = 0;i < iN;++i)
	{
		int iT, iB;
		cin >> iT >> iB;

		iMaxT = max(iMaxT, iT);
		iMinB = min(iMinB, iB);
	}

	int iAns = (iMaxT * iMinB) % 7 + 1;
	cout << iAns << "\n";
	return 0;
}
