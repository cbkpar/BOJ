#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iT;
	cin >> iT;
	while (iT--)
	{
		int iN, iS;
		cin >> iN >> iS;
		int iMin = 0;
		while (iN--)
		{
			int iSpeed;
			cin >> iSpeed;
			iMin = max(iMin, iSpeed);
		}
		cout << ((iMin * iS + 999) / 1000) << "\n";
	}

	return 0;
}
