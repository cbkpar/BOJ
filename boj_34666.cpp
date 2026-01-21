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

	int iT;
	cin >> iT;
	while (iT-- > 0)
	{
		int iGrade, iA, iB, iC;
		cin >> iGrade >> iA >> iB >> iC;

		bool bPossible = true;
		if (iGrade < 1 || iGrade > 2) bPossible = false;
		if (iC < 50) bPossible = false;

		int iCountA = 0;
		int iCountB = 0;
		if (iGrade == 1)
		{
			if (100 > iA * 3) ++iCountA;
			if (100 > iB * 3) ++iCountA;
			if (iA <= 21) ++iCountB;
			if (iB <= 21) ++iCountB;
		}
		else if (iGrade == 2)
		{
			if (90 > iA * 3) ++iCountA;
			if (90 > iB * 3) ++iCountA;
			if (iA <= 21) ++iCountB;
			if (iB <= 21) ++iCountB;
		}
		if (iCountA >= 2 || iCountB >= 1)
		{

		}
		else
		{
			bPossible = false;
		}

		cout << (bPossible ? "YES" : "NO") << "\n";
	}

	return 0;
}
