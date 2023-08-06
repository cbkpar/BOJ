#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iH1, iB1;
	cin >> iH1 >> iB1;

	int iH2, iB2;
	cin >> iH2 >> iB2;

	int iScore1 = iH1 * 3 + iB1;
	int iScore2 = iH2 * 3 + iB2;

	if (iScore1 > iScore2)
	{
		cout << "1 " << (iScore1 - iScore2) << "\n";
	}
	else if (iScore1 < iScore2)
	{
		cout << "2 " << (iScore2 - iScore1) << "\n";
	}
	else
	{
		cout << "NO SCORE\n";
	}
	return 0;
}
