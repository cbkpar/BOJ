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

	int iT;
	cin >> iT;
	for (int t = 1;t <= iT;++t)
	{
		int iK, iN;
		cin >> iK >> iN;
		int iAns = 0;
		for (int i = 0;i < iN;++i)
		{
			int iAmount;
			cin >> iAmount;
			if (iAmount > iK)
			{
				++iAns;
			}
		}
		cout << iAns << "\n";
	}
	return 0;
}
