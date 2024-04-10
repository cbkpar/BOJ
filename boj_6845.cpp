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
		int iY, iM, iD;
		cin >> iY >> iM >> iD;

		int iSum = iY * 10000 + iM * 100 + iD;

		if (iSum <= 19890227)
		{
			cout << "Yes" << "\n";
		}
		else
		{
			cout << "No" << "\n";
		}
	}
	return 0;
}
