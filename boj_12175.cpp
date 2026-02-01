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
	for (int t = 1;t <= iT;++t)
	{
		int iK, iV;
		cin >> iK >> iV;

		int iAns = 0;
		for (int i = 0;i <= iK;++i)
		{
			for (int j = i - iV;j <= i + iV;++j)
			{
				if (j<0 || j > iK) continue;
				for (int k = i - iV;k <= i + iV;++k)
				{
					if (k<0 || k > iK) continue;
					if (abs(j - k) > iV) continue;
					++iAns;
				}

			}
		}
		cout << "Case #" << t << ": " << iAns << "\n";
	}

	return 0;
}
