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
		int iN;
		cin >> iN;

		int iAns = 0;
		while (iN > 1)
		{
			if (iN % 2 == 0)
			{
				iN /= 2;

			}
			else
			{
				iAns += 1;
				iN = iN / 2 + 1;
			}
		}

		cout << iAns << "\n";
	}

	return 0;
}
