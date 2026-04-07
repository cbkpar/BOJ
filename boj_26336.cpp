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
		int iDist, iA, iB;
		cin >> iDist >> iA >> iB;
		cout << iDist << " " << iA << " " << iB << "\n";

		int iAns = 0;
		for (int i = 1;i < iDist;++i)
		{
			if (i % iA == 0 || i % iB == 0)
			{
				++iAns;
			}
		}
		cout << iAns << "\n";
	}

	return 0;
}
