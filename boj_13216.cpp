#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iWinA = 0;
	int iWinB = 0;

	string strGame;
	cin >> strGame;
	int iIndex = 0;

	while (true)
	{
		if (iWinA == 2 || iWinB == 2) break;
		int iScoreA = 0;
		int iScoreB = 0;
		while (true)
		{
			if (iScoreA == 21)
			{
				++iWinA;
				break;
			}
			if (iScoreB == 21)
			{
				++iWinB;
				break;
			}

			if (strGame[iIndex++] == 'A')
			{
				++iScoreA;
			}
			else
			{
				++iScoreB;
			}
		}
		cout << iScoreA << "-" << iScoreB << "\n";
	}
	cout << (iWinA > iWinB ? "A" : "B") << "\n";
	return 0;
}
