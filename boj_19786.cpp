#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int Calc(int iA, int iC, int iR, int iG, int iB)
{
	return iA * (iR * iR + iG * iG + iB * iB) + iC * min(iR, min(iG, iB));
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);

	int iT;
	cin >> iT;
	for (int t = 1;t <= iT;++t)
	{
		int iA, iC;
		cin >> iA >> iC;

		int iR, iG, iB;
		cin >> iR >> iG >> iB;

		int iMax = 0;
		iMax = max(iMax, Calc(iA, iC, iR + 1, iG, iB));
		iMax = max(iMax, Calc(iA, iC, iR, iG + 1, iB));
		iMax = max(iMax, Calc(iA, iC, iR, iG, iB + 1));

		if (iMax == Calc(iA, iC, iR + 1, iG, iB))
		{
			cout << "RED" << "\n";
		}
		else if (iMax == Calc(iA, iC, iR, iG + 1, iB))
		{
			cout << "GREEN" << "\n";
		}
		else
		{
			cout << "BLUE" << "\n";
		}
	}

	return 0;
}
