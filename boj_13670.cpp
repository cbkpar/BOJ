#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (true)
	{
		int iH1, iM1, iH2, iM2;
		cin >> iH1 >> iM1 >> iH2 >> iM2;
		if (iH1 == 0 && iM1 == 0 && iH2 == 0 && iM2 == 0) break;

		int iDiff = ((iH2 * 60 + iM2) - (iH1 * 60 + iM1) + 1440) % 1440;
		cout << iDiff << "\n";
	}
	return 0;
}
