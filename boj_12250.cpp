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
	for (int t = 1; t <= iT; ++t)
	{
		int iA, iB, iK;
		cin >> iA >> iB >> iK;

		int iAns = 0;
		for (int i = 0; i < iA; ++i)
		{
			for (int j = 0; j < iB; ++j)
			{
				if ((i & j) < iK)
				{
					++iAns;
				}
			}
		}
		cout << "Case #" << t << ": " << iAns << "\n";
	}
	return 0;
}
