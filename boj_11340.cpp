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
		int iP, iT, iM;
		cin >> iP >> iT >> iM;
		int iTotal = iP * 15 + iT * 20 + iM * 25;
		int iScore = (9039 - iTotal) / 40;
		if (iScore < 0 || iScore > 100)
		{
			cout << "impossible\n";
		}
		else
		{
			cout << iScore << "\n";
		}
	}
	return 0;
}
