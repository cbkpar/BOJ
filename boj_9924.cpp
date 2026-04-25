#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);

	int iA, iB;
	cin >> iA >> iB;

	int iAns = 0;
	while (iA != iB)
	{
		int iMax = max(iA, iB);
		int iMin = min(iA, iB);

		int iNewB = iMax - iMin;
		int iNewA = iMin;
		++iAns;

		iA = iNewA;
		iB = iNewB;
	}

	cout << iAns << "\n";
	return 0;
}
