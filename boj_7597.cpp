#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);

	while (true)
	{
		string strLine;
		cin >> strLine;

		if (strLine == "#") break;

		int iScoreA = 0;
		int iScoreB = 0;
		int iAnsA = 0;
		int iAnsB = 0;

		for (char ch : strLine)
		{
			if (ch == 'A') ++iScoreA;
			if (ch == 'B') ++iScoreB;

			if (iScoreA >= 4 && iScoreA >= iScoreB + 2)
			{
				++iAnsA;
				iScoreA = 0;
				iScoreB = 0;
			}
			if (iScoreB >= 4 && iScoreB >= iScoreA + 2)
			{
				++iAnsB;
				iScoreA = 0;
				iScoreB = 0;
			}
		}
		cout << "A " << iAnsA << " B " << iAnsB << "\n";
	}

	return 0;
}
